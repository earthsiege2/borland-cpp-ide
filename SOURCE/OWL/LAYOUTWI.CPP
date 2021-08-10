//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1992, 1993 by Borland International
//   source\owl\layoutwi.cpp
//   Implementation of class TLayoutWindow.
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\layoutwi.h>

DEFINE_RESPONSE_TABLE1(TLayoutWindow, TWindow)
  EV_WM_SIZE,
END_RESPONSE_TABLE;

IMPLEMENT_CASTABLE(TLayoutWindow);

//
//  class TFixed
//  ----- ------
//
//  simple fixed point class that maintains numbers as 16.16
//
class TFixed {
  public:
    long  Value;

    TFixed(int s = 0) {Value = long(s) << 16;}
    TFixed(int num, int denom) {Value = long(num) * 65536L / denom;}

    //
    //  unary negation operator
    //
    TFixed         operator -() {return -Value;}

    //
    //  postfix increment/decrement operators
    //
    void           operator ++(int) {Value += 1L << 16;}
    void           operator --(int) {Value -= 1L << 16;}

    //
    //  bitwise logical operators
    //
    TFixed         operator <<(unsigned n) {return Value << char(n);}
    TFixed         operator >>(unsigned n) {return Value >> char(n);}

    //
    // assignment operators
    //
    TFixed&        operator <<=(unsigned n) {Value <<= n; return *this;}
    TFixed&        operator >>=(unsigned n) {Value >>= n; return *this;}

    TFixed&        operator +=(const TFixed& f) {Value += f.Value; return *this;}

    TFixed&        operator -=(const TFixed& f) {Value -= f.Value; return *this;}

    TFixed&        operator *=(int s) {Value *= s; return *this;}
    TFixed&        operator *=(const TFixed& f) {Value = (Value >> 8) * (f.Value >> 8);
                                                 return *this;}

    TFixed&        operator /=(int s) {Value /= s; return *this;}
    TFixed&        operator /=(const TFixed& f) {Value /= f.Value >> 8; Value <<= 8;
                                                 return *this;}

    //
    // binary arithmetic operators
    //
    friend TFixed operator +(const TFixed& l,
                             const TFixed& r) {return l.Value + r.Value;}
    friend TFixed operator +(int           l,
                             const TFixed& r) {return TFixed(l) += r.Value;}
    friend TFixed operator +(const TFixed& l,
                             int           r) {return r + l;}

    friend TFixed operator -(const TFixed& l,
                             const TFixed& r) {return l.Value - r.Value;}
    friend TFixed operator -(int           l,
                             const TFixed& r) {return TFixed(l) -= r.Value;}
    friend TFixed operator -(const TFixed& l,
                             int           r) {return l - TFixed(r);}

    friend TFixed operator *(const TFixed& l,
                             const TFixed& r) {return (l.Value >> 8) * (r.Value >> 8);}
    friend TFixed operator *(int           l,
                             const TFixed& r) {return l * r.Value;}
    friend TFixed operator *(const TFixed& l,
                             int           r) {return l.Value * r;}

    friend TFixed operator /(const TFixed& l,
                             const TFixed& r) {return (l.Value /(r.Value >> 8)) << 8;}
    friend TFixed operator /(int           l,
                             const TFixed& r) {return (long(l) << 16) / r.Value;}
    friend TFixed operator /(const TFixed& l,
                             int           r) {return l.Value / r;}

    //
    //  equality operators
    //
    friend BOOL   operator ==(const TFixed& l,
                              const TFixed& r) {return l.Value == r.Value;}
    friend BOOL   operator !=(const TFixed& l,
                              const TFixed& r) {return l.Value != r.Value;}

    //
    // conversion operator to int
    //
    operator int() {return int(Value >> 16);}

  private:
    TFixed(long v) {Value = v;}
};

//----------------------------------------------------------------------------

struct TVariable;

//
// constraints can have up to three input variables
//
// the method for solving the constraint is represented as an ordered linear
// combination of the inputs and the constant with the constant expressed last
//
struct TConstraint {
  TVariable*    Inputs[3];
  TVariable*    Output;
  TFixed        OrderedCombination[4];
  TConstraint*  Next;

  TConstraint();

  BOOL  IsResolved();  // iff its inputs have been resolved
  int   Evaluate();
  int   NumActualInputs();
};

struct TVariable {
  int           Value;
  TConstraint*  DeterminedBy;  // 0 if variable is constant
  BOOL          Resolved;

  TVariable() {Value = 0; DeterminedBy = 0;}
};

//
// the layout metrics represent four equations. for equations that are
// "absolute" or "as is" we don't add a constraint and just set the variable
// value directly(and mark the variable as constant); otherwise we produce an
// ordered linear combination from the equation and add a constraint
//
struct TChildMetrics {
  public:
    BOOL            GeneratedConstraints;
    TWindow*        Child;
    TLayoutMetrics  Metrics;
    TVariable       Variables[4];  // x => 0, y => 1, right => 2, bottom => 3
    TChildMetrics*  Next;

    TChildMetrics(TWindow& child, TLayoutMetrics& metrics);
};

TChildMetrics::TChildMetrics(TWindow&        child,
                             TLayoutMetrics& metrics)
  : Child(&child), Metrics(metrics)
{
  GeneratedConstraints = FALSE;
  Next = 0;
}

TConstraint::TConstraint()
{
  Inputs[0] = Inputs[1] = Inputs[2] = 0;
  OrderedCombination[0] = OrderedCombination[1] = OrderedCombination[2] = 1;
  //
  // NOTE: OrderedCombination[3] was initialized to 0 by the TFixed ctor
  //
  Output = 0;
}

BOOL
TConstraint::IsResolved()
{
  return (!Inputs[0] || Inputs[0]->Resolved) &&
         (!Inputs[1] || Inputs[1]->Resolved) &&
         (!Inputs[2] || Inputs[2]->Resolved);
}

int
TConstraint::Evaluate()
{
  TFixed  value = OrderedCombination[3];  // initialize to constant part

  if (Inputs[0])
    value += OrderedCombination[0] * Inputs[0]->Value;

  if (Inputs[1])
    value += OrderedCombination[1] * Inputs[1]->Value;

  if (Inputs[2])
    value += OrderedCombination[2] * Inputs[2]->Value;

  return value;
}

int
TConstraint::NumActualInputs()
{
  for (int i = 0; i < 3; i++)
    if (!Inputs[i])
      break;

  return i;
}

//----------------------------------------------------------------------------

TLayoutMetrics::TLayoutMetrics()
{
  X.RelWin = 0;
  X.MyEdge = X.OtherEdge = lmLeft;
  X.Relationship = lmAsIs;
  X.Units = lmLayoutUnits;
  X.Value = 0;

  Y.RelWin = 0;
  Y.MyEdge = Y.OtherEdge = lmTop;
  Y.Relationship = lmAsIs;
  Y.Units = lmLayoutUnits;
  Y.Value = 0;

  Width.RelWin = 0;
  Width.MyEdge = Width.OtherEdge = lmWidth;
  Width.Relationship = lmAsIs;
  Width.Units = lmLayoutUnits;
  Width.Value = 0;

  Height.RelWin = 0;
  Height.MyEdge = Height.OtherEdge = lmHeight;
  Height.Relationship = lmAsIs;
  Height.Units = lmLayoutUnits;
  Height.Value = 0;
}

void
TLayoutMetrics::SetMeasurementUnits(TMeasurementUnits units)
{
  X.Units = Y.Units = Width.Units = Height.Units = units;
}

//----------------------------------------------------------------------------

TLayoutWindow::TLayoutWindow(TWindow*        parent,
                             const char far* title,
                             TModule*        module)
  : TWindow(parent, title, module)
{
  //
  // Initialize virtual bases, in case the derived-most used default ctor
  //
  TWindow::Init(parent, title, module);

  NumChildMetrics = 0;
  ChildMetrics = 0;
  Constraints = 0;
  Plan = 0;
  PlanIsDirty = FALSE;
  ClientSize.cx = ClientSize.cy = 0;

  //
  // allocate variables for the parent's left, top, right, and bottom and
  // mark them as resolved
  //
  Variables = new TVariable[4];
  Variables[0].Resolved = TRUE;
  Variables[1].Resolved = TRUE;
  Variables[2].Resolved = TRUE;
  Variables[3].Resolved = TRUE;
}

TLayoutWindow::~TLayoutWindow()
{
  delete Variables;

  //
  // free the child metrics
  //
  for (TChildMetrics* childMetrics = ChildMetrics; childMetrics;) {
    TChildMetrics*  tmp = childMetrics;

    childMetrics = childMetrics->Next;
    delete tmp;
  }

  //
  // free the constraints
  //
  ClearPlan();
  for (TConstraint* c = Constraints; c;) {
    TConstraint*  tmp = c;

    c = c->Next;
    delete tmp;
  }
}

void
TLayoutWindow::EvSize(UINT sizeType, TSize& size)
{
  TWindow::EvSize(sizeType, size);

  if (sizeType != SIZE_MINIMIZED && size != ClientSize) {
    ClientSize = size;
    Layout();
  }
}

void
TLayoutWindow::SetChildLayoutMetrics(TWindow& child, TLayoutMetrics& metrics)
{
  TChildMetrics*  childMetrics;

  PlanIsDirty = TRUE;

  if (ChildMetrics) {
    //
    // see if we already have metrics for the child
    //
    for (childMetrics = ChildMetrics; childMetrics; childMetrics = childMetrics->Next)
      if (childMetrics->Child == &child) {
        childMetrics->Child = &child;
        childMetrics->Metrics = metrics;
        //
        // get rid of the old constraints
        //
        RemoveConstraints(*childMetrics);
        return;
      }
  }

  childMetrics = new TChildMetrics(child, metrics);
  childMetrics->Next = ChildMetrics;
  ChildMetrics = childMetrics;
  NumChildMetrics++;
}

//
// Remove child (layout) metrics for a given child (if found) and update
// other children as necessary
//
BOOL
TLayoutWindow::RemoveChildLayoutMetrics(TWindow& child)
{
  TChildMetrics**  childMetrics;

  for (childMetrics = &ChildMetrics; *childMetrics; childMetrics = &(*childMetrics)->Next)
    if ((*childMetrics)->Child == &child) {
      //
      // unlink target metrics from list & clean up a bit
      //
      TChildMetrics*  tmp = *childMetrics;
      *childMetrics = tmp->Next;
      RemoveConstraints(*tmp);
      NumChildMetrics--;
      
      //
      // Update other child metrics now that removed metric is gone
      // Check for case where new relWin is lmParent and adjust other edge
      // to be what removed window was using. If an 'edge' is really a size,
      // then give up & just leave it asis. If the removed window had an edge
      // that was really a size, then use the other constraint in that
      // dimension (X or Y)
      //
      for (TChildMetrics* cm = ChildMetrics; cm; cm = cm->Next) {
        if (cm->Metrics.X.RelWin == &child) {
          RemoveConstraints(*cm);
          cm->Metrics.X.RelWin = tmp->Metrics.X.RelWin;
          if (cm->Metrics.X.RelWin == lmParent)
            cm->Metrics.X.OtherEdge = tmp->Metrics.X.OtherEdge;
        }
        if (cm->Metrics.Y.RelWin == &child) {
          RemoveConstraints(*cm);
          cm->Metrics.Y.RelWin = tmp->Metrics.Y.RelWin;
          if (cm->Metrics.Y.RelWin == lmParent)
            cm->Metrics.Y.OtherEdge = tmp->Metrics.Y.OtherEdge;
        }
        if (cm->Metrics.Width.RelWin == &child) {
          RemoveConstraints(*cm);
          if (cm->Metrics.Width.MyEdge == lmWidth)
            cm->Metrics.Width.Relationship = lmAsIs;
          else {
            if (tmp->Metrics.Width.MyEdge == lmWidth) {
              cm->Metrics.Width.RelWin = tmp->Metrics.X.RelWin;
              if (cm->Metrics.Width.RelWin == lmParent)
                cm->Metrics.Width.OtherEdge = tmp->Metrics.X.OtherEdge;
            } else {
              cm->Metrics.Width.RelWin = tmp->Metrics.Width.RelWin;
              if (cm->Metrics.Width.RelWin == lmParent)
                cm->Metrics.Width.OtherEdge = tmp->Metrics.Width.OtherEdge;
            }
          }
        }
        if (cm->Metrics.Height.RelWin == &child) {
          RemoveConstraints(*cm);
          if (cm->Metrics.Height.MyEdge == lmHeight)
            cm->Metrics.Height.Relationship = lmAsIs;
          else {
            if (tmp->Metrics.Height.MyEdge == lmHeight) {
              cm->Metrics.Height.RelWin = tmp->Metrics.Y.RelWin;
              if (cm->Metrics.Height.RelWin == lmParent)
                cm->Metrics.Height.OtherEdge = tmp->Metrics.Y.OtherEdge;
            } else {
              cm->Metrics.Height.RelWin = tmp->Metrics.Height.RelWin;
              if (cm->Metrics.Height.RelWin == lmParent)
                cm->Metrics.Height.OtherEdge = tmp->Metrics.Height.OtherEdge;
            }
          }
        }
      }
      
      //
      // finaly, delete target metrics
      //
      delete tmp;
      return TRUE;
    }

  return FALSE;
}

TChildMetrics*
TLayoutWindow::GetChildMetrics(TWindow& child)
{
  TChildMetrics*  childMetrics;

  for (childMetrics = ChildMetrics; childMetrics; childMetrics = childMetrics->Next)
    if (childMetrics->Child == &child)
      return childMetrics;

  return FALSE;
}

BOOL
TLayoutWindow::GetChildLayoutMetrics(TWindow& child, TLayoutMetrics& metrics)
{
  TChildMetrics*  childMetrics;

  for (childMetrics = ChildMetrics; childMetrics; childMetrics = childMetrics->Next)
    if (childMetrics->Child == &child) {
      metrics = childMetrics->Metrics;
      return TRUE;
    }

  return FALSE;
}

void
TLayoutWindow::RemoveChild(TWindow* child)
{
  TWindow::RemoveChild(child);
  RemoveChildLayoutMetrics(*child);
}

int
TLayoutWindow::LayoutUnitsToPixels(int value)
{
  const long  UnitsPerEM = 8;

  return int((long(value) * FontHeight + UnitsPerEM / 2) / UnitsPerEM);
}

static
BOOL
HasBorder(TWindow* win)
{
  //
  // we consider it to have a border unless it is a pop-up or child window
  // without WS_BORDER set
  //
  if ((win->Attr.Style & (WS_CHILD|WS_POPUP)) && !(win->Attr.Style & WS_BORDER))
    return FALSE;

  else
    return TRUE;
}

void
TLayoutWindow::ExecutePlan()
{
  for (TConstraint* c = Plan; c; c = c->Next)
    c->Output->Value = c->Evaluate();
}

void
TLayoutWindow::ClearPlan()
{
  if (Plan) {
    //
    // move all constraints that were in the plan back to the list of
    // constraints
    //
    if (!Constraints)
      Constraints = Plan;

    else {
      for (TConstraint* c = Constraints; c->Next; c = c->Next)
        ;

      c->Next = Plan;
    }

    Plan = 0;
  }
}

void
TLayoutWindow::BuildPlan()
{
  TChildMetrics*  childMetrics;
  TConstraint*    lastInPlan = 0;

  ClearPlan();

  //
  // mark all variables that aren't determined by a constraint as resolved
  //
  for (childMetrics = ChildMetrics; childMetrics; childMetrics = childMetrics->Next) {
    TVariable*  variable = childMetrics->Variables;

    variable->Resolved = variable->DeterminedBy ? FALSE : TRUE;
    variable++;
    variable->Resolved = variable->DeterminedBy ? FALSE : TRUE;
    variable++;
    variable->Resolved = variable->DeterminedBy ? FALSE : TRUE;
    variable++;
    variable->Resolved = variable->DeterminedBy ? FALSE : TRUE;
  }

  //
  // uses local propagation as much as possible (because it's fast)
  //
  // if cycles exist then we will end up with constraints that haven't been
  // added to the plan. we convert the remaining constraints into simultaneous
  // linear equations which we solve using Gaussian elimination
  //
  // look for constraints that have all their input variables resolved and
  // append them to the plan
  //
  for (BOOL foundOne = TRUE; foundOne;) {
    TConstraint*  c = Constraints;
    TConstraint*  previous = 0;

    foundOne = FALSE;

    while (c) {
      if (c->IsResolved()) {
        TConstraint*  resolved = c;

        c->Output->Resolved = TRUE;
        foundOne = TRUE;
        //
        // extract the constraint from the list of constraints
        //
        if (previous)
          previous->Next = c->Next;

        else
          Constraints = c->Next;

        c = c->Next;

        //
        // append the constraint to the plan
        //
        if (lastInPlan)
          lastInPlan->Next = resolved;

        else
          Plan = resolved;

        lastInPlan = resolved;

      } else {
        previous = c;
        c = c->Next;
      }
    }
  }

  //
  // Gaussian elimination not currently supported--give up
  //
  if (Constraints)
    THROW( TXWindow(this, IDS_LAYOUTINCOMPLETE) );
}

static int
FindInput(TConstraint* simplify, TVariable* input)
{
  for (int i = 0; i < 3; i++)
    if (simplify->Inputs[i] == input)
      return i;

  return -1;
}

//
// simplify constraint "simplify" by substituting constraint "_using"
//
// we do this when the two constraints are defined in terms of each other
//   1. the output of "simplify" is an input of "_using"
//   2. the output of "_using" is an input of "simplify"
//
// we do this to avoid a layout cycle
//
// "output" is the output variable for constraint "_using"
//
static
void
Simplify(TConstraint* simplify, TVariable* output, TConstraint* _using)
{
  if (!simplify)
    return;

  int  outputOfSimplify = FindInput(_using, simplify->Output);  // check #1
  int  target = FindInput(simplify, output);  // check #2

  if (outputOfSimplify != -1 && target != -1) {
    int  commonInputs[3];
    int  numInputsOfUsing = _using->NumActualInputs();

    //
    // count how many inputs are common between "simplify" and "_using"
    //
    for (int i = 0; i < numInputsOfUsing; i++)
      commonInputs[i] = FindInput(simplify, _using->Inputs[i]);

    //
    // since constraints only have room for 3 inputs we can not simplify if the
    // total number of the existing inputs minus the input we are going to back
    // substitute for plus the number of inputs added by "_using" (i.e. inputs
    // not common between the two constraints) exceeds 3
    //
    int  numInputsOfSimplify = simplify->NumActualInputs() - 1;
    int  newInputs = 0;

    //
    // compute the number of additional inputs contributed by "_using"
    //
    for (i = 0; i < numInputsOfUsing; i++)
      if (commonInputs[i] == -1 && i != outputOfSimplify)
        newInputs++;

    if (numInputsOfSimplify + newInputs > 3)
      return;

    TFixed  m = simplify->OrderedCombination[target];

    //
    // adjust the constant part
    //
    simplify->OrderedCombination[3] += m * _using->OrderedCombination[3];

    //
    // merge the common inputs
    //
    for (i = 0; i < numInputsOfUsing; i++)
      if (commonInputs[i] != -1)
        simplify->OrderedCombination[commonInputs[i]] +=
          m * _using->OrderedCombination[i];

    simplify->Inputs[target] = 0;  // input has been back substituted out

    //
    // if necessary shift the inputs following "output" (and their associated
    // mutiplier) left by one...
    //
    for (i = target + 1; i < 3; i++)
      if (simplify->Inputs[i]) {
        simplify->Inputs[i - 1] = simplify->Inputs[i];
        simplify->Inputs[i] = 0;
        simplify->OrderedCombination[i - 1] = simplify->OrderedCombination[i];
      }

    //
    // add the new inputs
    //
    for (i = 0; i < numInputsOfUsing; i++)
      if (commonInputs[i] == -1 && i != outputOfSimplify) {
        simplify->Inputs[numInputsOfSimplify] = _using->Inputs[i];
        simplify->OrderedCombination[numInputsOfSimplify] =
          m * _using->OrderedCombination[i];
        numInputsOfSimplify++;
      }

    //
    // now scale things back so that the output of "simplify" is 1
    //
    TFixed  f = 1 - m;

    simplify->OrderedCombination[3] /= f;
    for (i = 0; i < numInputsOfSimplify; i++)
      simplify->OrderedCombination[i] /= f;
  }
}

void
TLayoutWindow::AddConstraint(TChildMetrics&     metrics,
                             TLayoutConstraint* c,
                             TWhichConstraint   whichConstraint)
{
  int           index;
  TVariable*    output;
  TConstraint*  result = new TConstraint;

  //
  // set the output variable
  //
  if (whichConstraint == XConstraint && metrics.Metrics.X.MyEdge == lmRight)
    output = &metrics.Variables[2];

  else if (whichConstraint == YConstraint && metrics.Metrics.Y.MyEdge == lmBottom)
    output = &metrics.Variables[3];

  else
    output = &metrics.Variables[whichConstraint];

  //
  // set the inputs based on the edge
  //
  if (c->Relationship != lmAbsolute && c->Relationship != lmAsIs) {
    TVariable*  variables;

    if (c->RelWin == lmParent)
      variables = Variables;

    else {
      TChildMetrics*  relWinMetrics = GetChildMetrics(*c->RelWin);
      if (!relWinMetrics) {
        delete result;
        THROW( TXWindow(this, IDS_LAYOUTBADRELWIN) );
      }
      variables = relWinMetrics->Variables;
    }

    switch (c->OtherEdge) {
      case lmLeft:
      case lmTop:
      case lmRight:
      case lmBottom:
        result->Inputs[0] = &variables[c->OtherEdge];
        break;

      case lmWidth:
      case lmHeight:
        //
        // width => right - left + 1
        // height => bottom - top + 1
        //
        result->Inputs[0] = &variables[c->OtherEdge - lmWidth+lmRight];
        result->Inputs[1] = &variables[c->OtherEdge - lmWidth+lmLeft];
        result->OrderedCombination[1] = -1;
        result->OrderedCombination[3] = 1;
        break;

      case lmCenter:
        switch (whichConstraint) {
          case XConstraint:
          case WidthConstraint:
            //
            // center => (left + right) / 2
            //
            result->Inputs[0] = &variables[0];
            result->Inputs[1] = &variables[2];
            break;

          case YConstraint:
          case HeightConstraint:
            //
            // center => (top + bottom) / 2
            //
            result->Inputs[0] = &variables[1];
            result->Inputs[1] = &variables[3];
            break;
        }
        result->OrderedCombination[0] = result->OrderedCombination[1] = TFixed(1,2);
        break;
    }
  }

  //
  // now store the constant term as the last of the ordered linear combination
  //
  // we must do this after setting the inputs
  //
  // NOTE: we cannot assume that the constant part is 0, because it might have
  //       been set above
  //
  switch (c->Relationship) {
    case lmAsIs:
      result->OrderedCombination[3] += whichConstraint == WidthConstraint ?
                                                          metrics.Child->Attr.W :
                                                          metrics.Child->Attr.H;
      break;

    case lmAbsolute:
    case lmSameAs:
    case lmBelow:
    case lmAbove: {
      int  value = c->Units == lmPixels ? c->Value : LayoutUnitsToPixels(c->Value);

      if (c->Relationship == lmAbove)
        value = -value - 1;

      else if (c->Relationship == lmBelow)
        value++;

      result->OrderedCombination[3] += value;
      break;
    }

    case lmPercentOf:
      TFixed  percent = c->Percent;

      percent /= 100;
      result->OrderedCombination[0] *= percent;
      result->OrderedCombination[3] *= percent;

      switch (c->OtherEdge) {
        case lmWidth:
        case lmHeight:
        case lmCenter:
          result->OrderedCombination[1] *= percent;
          break;
      }
      break;
  }

  //
  // now handle cases where the left hand side is width, height, or center
  //
  // this must be done last...
  //
  if (result->Inputs[0])
    index = result->Inputs[1] ? 2 : 1;

  else
    index = 0;

  switch (c->MyEdge) {
    case lmWidth:
      if (whichConstraint == XConstraint || metrics.Metrics.X.MyEdge == lmRight) {
        //
        // rewrite "right - left + 1 = " as "left = right - (...) + 1"
        //
        for (int i = 0; i < index; i++)
          result->OrderedCombination[i] = -result->OrderedCombination[i];

        result->OrderedCombination[3] = -result->OrderedCombination[3];
        result->OrderedCombination[3]++;
        result->Inputs[index] = &metrics.Variables[2];

        if (whichConstraint == WidthConstraint)
          output = &metrics.Variables[XConstraint];

      } else {
        //
        // rewrite "right - left + 1 = " as "right = left + ... - 1"
        //
        result->Inputs[index] = &metrics.Variables[0];
        result->OrderedCombination[3]--;

        Simplify(metrics.Variables[0].DeterminedBy, output, result);
      }
      break;

    case lmHeight:
      if (whichConstraint == YConstraint || metrics.Metrics.Y.MyEdge == lmBottom) {
        //
        // rewrite "bottom - top + 1 = " as "top = bottom - (...) + 1"
        //
        for (int i = 0; i < index; i++)
          result->OrderedCombination[i] = -result->OrderedCombination[i];

        result->OrderedCombination[3] = -result->OrderedCombination[3];
        result->OrderedCombination[3]++;
        result->Inputs[index] = &metrics.Variables[3];

        if (whichConstraint == HeightConstraint)
          output = &metrics.Variables[YConstraint];

      } else {
        //
        // rewrite "bottom - top + 1 = " as "bottom = top + ... - 1"
        //
        result->Inputs[index] = &metrics.Variables[1];
        result->OrderedCombination[3]--;

        Simplify(metrics.Variables[1].DeterminedBy, output, result);
      }
      break;

    case lmCenter:
      TVariable*  input = &metrics.Variables[0];  // left

      switch (whichConstraint) {
        case XConstraint:
          //
          // rewrite "(left + right) / 2 = " as "left = -right + 2 * (...)"
          //
          input += 2;  // right
          break;

        case YConstraint:
          //
          // rewrite "(top + bottom) / 2 = " as "top = -bottom + 2 * (...)"
          //
          input += 3;  // bottom
          break;

        case WidthConstraint:
          //
          // rewrite "(left + right) / 2 = " as "right = -left + 2 * (...)" or
          // "left = -right + 2 * (...)" depending on whether the "x" constraint
          // is left or right
          //
          if (metrics.Metrics.X.MyEdge == lmRight) {
            input += 2;  // right
            output = &metrics.Variables[XConstraint];
          }
          break;

        case HeightConstraint:
          //
          // rewrite "(top + bottom) / 2 = " as "bottom = -top + 2 * (...)" or
          // "top = -bottom + 2 * (...)" depending on whether the "y" constraint
          // is top or bottom
          //
          if (metrics.Metrics.Y.MyEdge != lmBottom)
            input++;  // top

          else {
            input += 3;  // bottom
            output = &metrics.Variables[XConstraint];
          }
          break;
      }
      result->Inputs[index] = input;
      for (int i = 0; i < index; i++)
        result->OrderedCombination[i] <<= 1;

      result->OrderedCombination[3] <<= 1;
      result->OrderedCombination[index] = -1;
      break;
  }

  //
  // now set the constraint output
  //
  output->DeterminedBy = result;
  result->Output = output;

  //
  // add the constraint to the list of constraints
  //
  result->Next = Constraints;
  Constraints = result;
}

void
TLayoutWindow::RemoveConstraints(TChildMetrics& childMetrics)
{
  TVariable*  variable = childMetrics.Variables;

  PlanIsDirty = TRUE;
  ClearPlan();
  childMetrics.GeneratedConstraints = FALSE;

  for (int i = 0; i < 4; i++) {
    TConstraint*  constraint = variable->DeterminedBy;

    variable->Value = 0;

    if (constraint) {
      //
      // remove the constraint from the list of constraints
      //
      if (Constraints == constraint)
        Constraints = constraint->Next;

      else
        for (TConstraint*  c = Constraints; c->Next; c = c->Next)
          if (c->Next == constraint) {
            c->Next = constraint->Next;
            break;
          }

      delete constraint;
      variable->DeterminedBy = 0;
    }

    variable++;
  }
}

void
TLayoutWindow::BuildConstraints(TChildMetrics& childMetrics)
{
  //
  // NOTE: to get uniformity we consider the window edges to sit on pixels
  //       and not between pixels. so our idea of right is left + width - 1
  //       and not left + width
  //
  if (!childMetrics.GeneratedConstraints) {
    TLayoutConstraint*  c = &childMetrics.Metrics.X;

    childMetrics.GeneratedConstraints = TRUE;

    //
    // "x" can be one of: left, right, center
    //
    if (c->Relationship == lmAsIs)
      if (c->MyEdge == lmLeft)
        childMetrics.Variables[0].Value = childMetrics.Child->Attr.X;

      else
        childMetrics.Variables[2].Value = childMetrics.Child->Attr.X +
                                          childMetrics.Child->Attr.W - 1;

    else if (c->Relationship == lmAbsolute && c->MyEdge != lmCenter) {
      int  value = c->Units == lmPixels ? c->Value : LayoutUnitsToPixels(c->Value);

      childMetrics.Variables[c->MyEdge == lmLeft ? 0 : 2].Value = value;

    } else {
      AddConstraint(childMetrics, c, XConstraint);
    }

    //
    // "y" can be one of: top, bottom, center
    //
    c = &childMetrics.Metrics.Y;

    if (c->Relationship == lmAsIs)
      if (c->MyEdge == lmTop)
        childMetrics.Variables[1].Value = childMetrics.Child->Attr.Y;

      else
        childMetrics.Variables[3].Value = childMetrics.Child->Attr.Y +
                                          childMetrics.Child->Attr.H - 1;

    else if (c->Relationship == lmAbsolute && c->MyEdge != lmCenter) {
      int  value = c->Units == lmPixels ? c->Value : LayoutUnitsToPixels(c->Value);

      childMetrics.Variables[c->MyEdge == lmTop ? 1 : 3].Value = value;

    } else {
      AddConstraint(childMetrics, c, YConstraint);
    }

    //
    // "width" can be one of: width, right, center
    //
    c = &childMetrics.Metrics.Width;

    if (c->MyEdge == lmRight && (c->Relationship == lmAsIs || c->Relationship == lmAbsolute))
      childMetrics.Variables[2].Value = c->Relationship == lmAsIs ?
                                        childMetrics.Child->Attr.X +
                                        childMetrics.Child->Attr.W - 1 :
                                        c->Units == lmPixels ? c->Value : LayoutUnitsToPixels(c->Value);

    else
      AddConstraint(childMetrics, c, WidthConstraint);

    //
    // "height" can be one of: height, bottom, center
    //
    c = &childMetrics.Metrics.Height;

    if (c->MyEdge == lmBottom && (c->Relationship == lmAsIs || c->Relationship == lmAbsolute))
      childMetrics.Variables[3].Value = c->Relationship == lmAsIs ?
                                        childMetrics.Child->Attr.Y +
                                        childMetrics.Child->Attr.H - 1 :
                                        c->Units == lmPixels ? c->Value : LayoutUnitsToPixels(c->Value);

    else
      AddConstraint(childMetrics, c, HeightConstraint);
  }
}

void
TLayoutWindow::GetFontHeight()
{
  HDC         hDC = ::GetDC(0);
  HFONT       hFont = (HFONT)HandleMessage(WM_GETFONT);
  HGDIOBJ     hOldFont;
  TEXTMETRIC  tm;

  if (hFont)
    hOldFont = ::SelectObject(hDC, hFont);

  ::GetTextMetrics(hDC, &tm);
  FontHeight = tm.tmHeight;

  if (hFont)
    ::SelectObject(hDC, hOldFont);

  ::ReleaseDC(0, hDC);
}

void
TLayoutWindow::Layout()
{
  if (ChildMetrics) {
    TChildMetrics*  childMetrics;

    GetFontHeight();

    //
    // initialize the parent's variables
    //
    Variables[2].Value = ClientSize.cx - 1;
    Variables[3].Value = ClientSize.cy - 1;

    if (HasBorder(this)) {
      int  cxBorder = GetSystemMetrics(SM_CXBORDER);
      int  cyBorder = GetSystemMetrics(SM_CYBORDER);

      Variables[0].Value = -cxBorder;
      Variables[1].Value = -cyBorder;
      Variables[2].Value += cxBorder;
      Variables[3].Value += cyBorder;

    } else {
      Variables[0].Value = 0;
      Variables[1].Value = 0;
    }

    //
    // Rebuild layout plan if necessary
    //
    if (PlanIsDirty) {
      PlanIsDirty = FALSE;

      for (childMetrics = ChildMetrics; childMetrics;
           childMetrics = childMetrics->Next)
        BuildConstraints(*childMetrics);

      BuildPlan();
    }

    //
    // Use the plan to calculate actual child window position values
    //
    ExecutePlan();

    //
    // now do the actual resizing of the windows
    //
    for (childMetrics = ChildMetrics; childMetrics; childMetrics = childMetrics->Next) {
      TWindow*    win = childMetrics->Child;
      TVariable*  variables = childMetrics->Variables;

      if (win->HWindow) {
        win->SetWindowPos(
          0,
          variables[0].Value,
          variables[1].Value,
          variables[2].Value - variables[0].Value + 1,
          variables[3].Value - variables[1].Value + 1,
          SWP_NOZORDER | SWP_NOACTIVATE
        );

      } else {
        win->Attr.X = variables[0].Value;
        win->Attr.Y = variables[1].Value;
        win->Attr.W = variables[2].Value - variables[0].Value + 1;
        win->Attr.H = variables[3].Value - variables[1].Value + 1;
      }
    }
  }
}
