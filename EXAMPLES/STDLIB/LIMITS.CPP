 #include <limits>

 using namespace std;

 int main()
 {
    numeric_limits<float> float_info;
    if (float_info.is_specialized && float_info.has_infinity)
    {
      //
      // Get value of infinity.
      //
      float finfinity=float_info.infinity();
    }
    return 0;
 }
