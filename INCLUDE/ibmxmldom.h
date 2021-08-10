//---------------------------------------------------------------------------
#ifndef ibmxmldomH
#define ibmxmldomH
//---------------------------------------------------------------------------

#ifdef LINUX
#define ULONG unsigned long
#define LONG long
struct GUID
{
 unsigned int p1;
 unsigned short p2;
 unsigned short p3;
 char p4[8];
};
#define DEFINE_GUID( name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8 ) extern const GUID name = { l, w1, w2, { b1, b2, b3, b4, b5, b6, b7, b8 } }
#define REFIID const GUID &
#define STDCALL __attribute__ ((__stdcall__))
#define FASTCALL 
#define COMINTF __attribute__ ((com_interface))
#define HRESULT int 
#define __RPC_FAR 

// From winerror.h
#define E_NOINTERFACE 0x80004002 
#define S_OK 	(0x00000000) 
#define S_FALSE (0x00000001) 

//wchar_t in Linux is an int (4 bytes)
//Use short instead of wchar_t for BSTR
#define BSTR unsigned short *
#define DOMNodeType short


class COMINTF IUnknown
{
public:
  virtual HRESULT STDCALL QueryInterface( const GUID &guid, void ** ppv ) = 0;
  virtual ULONG STDCALL AddRef() = 0;
  virtual ULONG STDCALL Release() = 0;
};

DEFINE_GUID(IID_IUnknown, 0x00000000, 0x0000, 0x0000, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46);


#ifdef __SMP__
#define LOCK "lock ; "
#else
#define LOCK ""
#endif

// This following piece of code for atomic_inc/dec is swiped from linux kernel
/*
 * Make sure gcc doesn't try to be clever and move things around
 * on us. We need to use _exactly_ the address the user gave us,
 * not some alias that contains the same information.
 */
#define __atomic_fool_gcc(x) (*(volatile struct { int a[100]; } *)x)

#ifdef __SMP__
typedef struct { volatile int counter; } atomic_t;
#else
typedef struct { int counter; } atomic_t;
#endif

static __inline__ void atomic_inc(volatile atomic_t *v)
{
	__asm__ __volatile__(
		LOCK "incl %0\n\t"
		:"=m" (__atomic_fool_gcc(v))
		:"m" (__atomic_fool_gcc(v)));
}

static __inline__ void atomic_dec(volatile atomic_t *v)
{
	__asm__ __volatile__(
		LOCK "decl %0"
		:"=m" (__atomic_fool_gcc(v))
		:"m" (__atomic_fool_gcc(v)));
}


#endif

#ifdef WINDOWS
#define FASTCALL __fastcall
#define COMINTF 
#define STDCALL __stdcall
#endif

class COMINTF FASTCALL  IDOMImplementation;
class COMINTF FASTCALL  IDOMNode;
class COMINTF FASTCALL  IDOMNodeList;
class COMINTF FASTCALL  IDOMNamedNodeMap;
class COMINTF FASTCALL  IDOMCharacterData;
class COMINTF FASTCALL  IDOMAttribute;
class COMINTF FASTCALL  IDOMElement;
class COMINTF FASTCALL  IDOMText;
class COMINTF FASTCALL  IDOMComment;
class COMINTF FASTCALL  IDOMCDATASection;
class COMINTF FASTCALL  IDOMDocumentType;
class COMINTF FASTCALL  IDOMNotation;
class COMINTF FASTCALL  IDOMEntity;
class COMINTF FASTCALL  IDOMEntityReference;
class COMINTF FASTCALL  IDOMProcessingInstruction;
class COMINTF FASTCALL  IDOMDocumentFragment;
class COMINTF FASTCALL  IDOMDocument;
class COMINTF FASTCALL  IDOMPersist;

typedef IDOMImplementation *IDOMImplementationPtr;
typedef IDOMNode *IDOMNodePtr;
typedef IDOMNodeList *IDOMNodeListPtr;
typedef IDOMNamedNodeMap *IDOMNamedNodeMapPtr;
typedef IDOMCharacterData *IDOMCharacterDataPtr;
typedef IDOMAttribute *IDOMAttributePtr;
typedef IDOMElement *IDOMElementPtr;
typedef IDOMText *IDOMTextPtr;
typedef IDOMComment *IDOMCommentPtr;
typedef IDOMCDATASection *IDOMCDATASectionPtr;
typedef IDOMDocumentType *IDOMDocumentTypePtr;
typedef IDOMNotation *IDOMNotationPtr;
typedef IDOMEntity *IDOMEntityPtr;
typedef IDOMEntityReference *IDOMEntityReferencePtr;
typedef IDOMProcessingInstruction *IDOMProcessingInstructionPtr;
typedef IDOMDocumentFragment *IDOMDocumentFragmentPtr;
typedef IDOMDocument *IDOMDocumentPtr;
typedef IDOMPersist *IDOMPersistPtr;

typedef struct {
    union
    {
      unsigned short     VType; // Delphi-compatible - Variant Type member
      unsigned short     vt;    // tagVARIANT compatible member
    };
    unsigned short Reserved1;
    unsigned short Reserved2;
    unsigned short Reserved3;
    BSTR           bstrVal;
    int		   pad;
} MyVariant;

class UnkImpl : public IUnknown
{
public:
  virtual STDCALL HRESULT QueryInterface(REFIID riid, void __RPC_FAR *__RPC_FAR *ppvObject);
  virtual ULONG STDCALL AddRef(void);
  virtual ULONG STDCALL Release(void);

  UnkImpl() :
    FRefCount(1) {};

private:
  LONG FRefCount;
};

class COMINTF FASTCALL  IDOMPersist : public UnkImpl
{
public:
  static int count;
  virtual STDCALL HRESULT get_xml(BSTR *result) = 0;
  virtual STDCALL HRESULT asyncLoadState(int *result) = 0;
  virtual STDCALL HRESULT load(MyVariant source, bool *result) = 0;
  virtual STDCALL HRESULT loadxml(BSTR Value, bool *result) = 0;
  virtual STDCALL HRESULT save(MyVariant destination) = 0;
  virtual STDCALL HRESULT set_OnAsyncLoad(const void* Sender,
    const void* Handler) = 0;
  IDOMPersist() : UnkImpl() {} ;
//  __property   DOMString xml = {read = get_xml, write = set_xml};
};

class COMINTF FASTCALL  IDOMImplementation : public UnkImpl
{
public:
  virtual STDCALL HRESULT hasFeature(BSTR feature, BSTR version, bool *result) = 0;
  virtual STDCALL HRESULT createDocumentType(BSTR qualifiedName,
    BSTR publicId, BSTR systemId, IDOMDocumentTypePtr *result) = 0;
  virtual STDCALL HRESULT createDocument(BSTR namespaceURI,
    BSTR qualifiedName,  IDOMDocumentTypePtr doctype,
    IDOMDocumentPtr *result) = 0;
  virtual STDCALL HRESULT createDocument(InputSource &insrc, 
    IDOMDocumentTypePtr doctype, IDOMDocumentPtr *result) = 0;
  IDOMImplementation() : UnkImpl() {};
};

class COMINTF FASTCALL  IDOMNodeList : public UnkImpl
{
public:
  virtual STDCALL HRESULT get_item(unsigned int index, IDOMNodePtr *result) = 0;
  virtual STDCALL HRESULT get_length(unsigned int *result) = 0;
//  __property   long            length = {read = get_length};

  IDOMNodeList() : UnkImpl() {};
};

class COMINTF FASTCALL  IDOMNamedNodeMap : public UnkImpl
{
public:
  virtual STDCALL HRESULT get_item(unsigned int index, IDOMNodePtr *result) = 0;
  virtual unsigned int get_length(void) = 0;
  virtual STDCALL HRESULT getNamedItem(BSTR name, IDOMNodePtr *result) = 0;
  virtual STDCALL HRESULT setNamedItem(IDOMNodePtr newItem, IDOMNodePtr *result) = 0;
  virtual STDCALL HRESULT removeNamedItem(BSTR name, IDOMNodePtr *result) = 0;

  //DOM Level-2
  virtual STDCALL HRESULT getNamedItemNS(BSTR namespaceURI,
		                           BSTR localname, 
					   IDOMNodePtr *result) = 0;

  virtual STDCALL HRESULT setNamedItemNS(IDOMNodePtr newItem, 
		                           IDOMNodePtr *result) = 0;

  virtual STDCALL HRESULT removeNamedItemNS(BSTR namespaceURI,
		                           BSTR localname, 
					   IDOMNodePtr *result) = 0;

  IDOMNamedNodeMap() : UnkImpl() {};
#ifdef BORLANDC
  __property   long            length = {read = get_length};
#endif
};

class COMINTF FASTCALL  IDOMNode : public UnkImpl
{
public:
  virtual STDCALL HRESULT get_nodeName(BSTR *result) = 0;
  virtual STDCALL HRESULT get_nodeValue(BSTR *result) = 0;
  virtual void set_nodeValue(BSTR value) = 0;
  virtual STDCALL HRESULT get_nodeType(DOMNodeType *result) = 0;
  virtual STDCALL HRESULT get_parentNode(IDOMNodePtr *result) = 0;
  virtual STDCALL HRESULT get_childNodes(IDOMNodeListPtr *result) = 0;
  virtual STDCALL HRESULT get_firstChild(IDOMNodePtr *result) = 0;
  virtual STDCALL HRESULT get_lastChild(IDOMNodePtr *result) = 0;
  virtual STDCALL HRESULT get_previousSibling(IDOMNodePtr *result) = 0;
  virtual STDCALL HRESULT get_nextSibling(IDOMNodePtr *result) = 0;
  virtual STDCALL HRESULT get_attributes(IDOMNamedNodeMapPtr *result) = 0;
  virtual STDCALL HRESULT get_ownerDocument(IDOMDocumentPtr *result) = 0;
  virtual STDCALL HRESULT get_namespaceURI(BSTR *result) = 0;
  virtual STDCALL HRESULT get_prefix(BSTR *result) = 0;
  virtual STDCALL HRESULT get_localname(BSTR *result) = 0;
  virtual STDCALL HRESULT insertBefore(IDOMNodePtr newChild,
                               IDOMNodePtr refChild,
                               IDOMNodePtr *result) = 0;
  virtual STDCALL HRESULT replaceChild(IDOMNodePtr newChild,
                               IDOMNodePtr oldChild,
                               IDOMNodePtr *result) = 0;
  virtual STDCALL HRESULT removeChild(IDOMNodePtr childNode,
                              IDOMNodePtr *result) = 0;
  virtual STDCALL HRESULT appendChild(IDOMNodePtr newChild,
                              IDOMNodePtr *result) = 0;
  virtual STDCALL HRESULT hasChildNodes(bool *result) = 0; 
  virtual STDCALL HRESULT cloneNode(bool deep, IDOMNodePtr *result) = 0; 

  virtual void normalize(void) = 0; 
  virtual STDCALL HRESULT supports(BSTR feature,
		                          BSTR version,
					  bool *result) = 0; 
  //virtual void set_prefix(BSTR prefix) = 0;


  IDOMNode() :
    UnkImpl() {};
};

class COMINTF FASTCALL  IDOMCharacterData : public IDOMNode
{
public:
  virtual STDCALL HRESULT get_data(BSTR *result) = 0;
  virtual void set_data(BSTR data) = 0;
  virtual STDCALL HRESULT get_length(unsigned int *result) = 0;
  virtual STDCALL HRESULT substringData(unsigned int offset, 
		                          unsigned int count, BSTR *result) = 0;
  virtual void appendData(BSTR data) = 0;
  virtual void insertData(long offset, BSTR data) = 0;
  virtual void deleteData(long offset, long count) = 0;
  virtual void replaceData(long offset, long count, BSTR data) = 0;
//  __property   BSTR      data = {read = get_data, write = set_data};
//  __property   long            length = {read = get_length};

  IDOMCharacterData() : IDOMNode () {} ; 
};

class COMINTF FASTCALL  IDOMAttribute : public IDOMNode
{
public:
  virtual STDCALL HRESULT get_name(BSTR *result) = 0;
  virtual STDCALL HRESULT get_specified(bool *result) = 0;
  virtual STDCALL HRESULT get_value(BSTR *result) = 0;
  virtual void set_value(BSTR attributeValue) = 0;
  virtual STDCALL HRESULT get_ownerElement(IDOMElementPtr *result) = 0;
//  __property   BSTR        name = {read = get_name};
//  __property   BSTR        value = {read = get_value, write = set_value};
  IDOMAttribute() : IDOMNode () {} ; 
};

class COMINTF FASTCALL  IDOMElement : public IDOMNode
{
public:
  virtual STDCALL HRESULT get_tagName(BSTR *result) = 0;
  virtual STDCALL HRESULT getAttribute(BSTR name, BSTR *result) = 0;
  virtual void setAttribute(BSTR name, BSTR value) = 0;
  virtual void removeAttribute(BSTR name) = 0;
  virtual STDCALL HRESULT getAttributeNode(BSTR name, IDOMAttributePtr *result) = 0;
  virtual STDCALL HRESULT setAttributeNode(IDOMAttributePtr DOMAttribute, IDOMAttributePtr *result) = 0;
  virtual STDCALL HRESULT removeAttributeNode(IDOMAttributePtr DOMAttribute, IDOMAttributePtr *result) = 0;
  virtual STDCALL HRESULT getElementsByTagName(BSTR tagName, IDOMNodeListPtr *result) = 0;

  //DOM Level-2
  virtual STDCALL HRESULT getAttributeNS(BSTR namespaceURI, 
		                           BSTR qualifiedName,
					   BSTR *result) = 0;
  virtual void setAttributeNS(BSTR namespaceURI, 
		                      BSTR qualifiedName,
				      BSTR value) = 0;
  virtual void removeAttributeNS(BSTR namespaceURI, 
		                         BSTR localName) = 0;
  virtual STDCALL HRESULT getAttributeNodeNS(BSTR namespaceURI, 
		                   BSTR localName,
				   IDOMAttributePtr *result) = 0;
  virtual STDCALL HRESULT setAttributeNodeNS(
				   IDOMAttributePtr newAttr,
				   IDOMAttributePtr *result) = 0;
  virtual STDCALL HRESULT getElementsByTagNameNS(BSTR namespaceURI, 
		                   BSTR localName,
				   IDOMNodeListPtr *result) = 0;
  // IBM DOM doesn't implement this method.
  // This is here just to be consistent with pascal interface.
  virtual STDCALL HRESULT hasAttribute(BSTR name, bool *result) = 0;
  IDOMElement() : IDOMNode () {} ; 
};

class COMINTF FASTCALL  IDOMText : public IDOMCharacterData
{
public:
  virtual STDCALL HRESULT splitText(unsigned int offset, 
		                      IDOMTextPtr *result) = 0;
  IDOMText() : IDOMCharacterData () {} ; 
};

class COMINTF FASTCALL  IDOMComment : public IDOMCharacterData
{
public:
  IDOMComment() : IDOMCharacterData () {} ; 

};

class COMINTF FASTCALL  IDOMCDATASection : public IDOMText
{
public:

  IDOMCDATASection() : IDOMText () {} ; 
};

class COMINTF FASTCALL  IDOMDocumentType : public IDOMNode
{
public:
  virtual STDCALL HRESULT get_name(BSTR *result) = 0;
  virtual STDCALL HRESULT get_entities(IDOMNamedNodeMapPtr *result) = 0;
  virtual STDCALL HRESULT get_notations(IDOMNamedNodeMapPtr *result) = 0;

  //DOM Level-2
  virtual STDCALL HRESULT get_publicId(BSTR *result) = 0;
  virtual STDCALL HRESULT get_systemId(BSTR *result) = 0;
  virtual STDCALL HRESULT get_internalSubset(BSTR *result) = 0;


//  __property   BSTR            name = {read = get_name};
//  __property   IDOMNamedNodeMapPtr entities = {read = get_entities};
  IDOMDocumentType() : IDOMNode () {} ; 
};

class COMINTF FASTCALL  IDOMNotation : public IDOMNode
{
public:
  virtual STDCALL HRESULT get_publicId(BSTR *result) = 0;
  virtual STDCALL HRESULT get_systemId(BSTR *result) = 0;

  IDOMNotation() : IDOMNode () {} ; 
};

class COMINTF FASTCALL  IDOMEntity : public IDOMNode
{
public:
  virtual STDCALL HRESULT get_publicId(BSTR *result) = 0;
  virtual STDCALL HRESULT get_systemId(BSTR *result) = 0;
  virtual STDCALL HRESULT get_notationName(BSTR *result) = 0;

  IDOMEntity() : IDOMNode () {} ; 
};

class COMINTF FASTCALL  IDOMEntityReference : public IDOMNode
{
public:

  IDOMEntityReference() : IDOMNode () {} ; 
};

class COMINTF FASTCALL  IDOMProcessingInstruction : public IDOMNode
{
public:
  virtual STDCALL HRESULT get_target(BSTR *result) = 0;
  virtual STDCALL HRESULT get_data(BSTR *result) = 0;
  virtual void set_data(BSTR value) = 0;

  IDOMProcessingInstruction() : IDOMNode () {} ; 
};

class COMINTF FASTCALL  IDOMDocumentFragment : public IDOMNode
{
public:
  IDOMDocumentFragment() : IDOMNode () {} ; 

};

class COMINTF FASTCALL  IDOMDocument : public IDOMNode
{
public:
  virtual STDCALL HRESULT get_doctype(IDOMDocumentTypePtr *result) = 0;
  virtual STDCALL HRESULT get_implementation(IDOMImplementationPtr* result) = 0;
  virtual STDCALL HRESULT get_documentElement(IDOMElementPtr* result) = 0;
  
  // IBM DOM doesn't implement this method.
  // This is here just to be consistent with pascal interface.
  virtual void set_documentElement(IDOMElementPtr element) = 0 ;

  virtual STDCALL HRESULT createElement(BSTR tagName, IDOMElementPtr *result) = 0;
  virtual STDCALL HRESULT createDocumentFragment(IDOMDocumentFragmentPtr* result) = 0;
  virtual STDCALL HRESULT createTextNode(BSTR data, IDOMTextPtr *result) = 0;
  virtual STDCALL HRESULT createComment(BSTR data, IDOMCommentPtr *result) = 0;
  virtual STDCALL HRESULT createCDATASection(BSTR data, IDOMCDATASectionPtr *result) = 0;
  virtual STDCALL HRESULT createProcessingInstruction(BSTR target, 
                          BSTR data,
		          IDOMProcessingInstructionPtr *result) = 0;
  virtual STDCALL HRESULT createAttribute(BSTR name, IDOMAttributePtr *result) = 0;
  virtual STDCALL HRESULT createEntityReference(BSTR name,
		                 IDOMEntityReferencePtr *result) = 0;
  virtual STDCALL HRESULT getElementsByTagName(BSTR tagName,
		  IDOMNodeListPtr *result) = 0;
  // DOM Level-2

  virtual STDCALL HRESULT importNode (IDOMNodePtr importedNode,
		                        bool deep,
					IDOMNodePtr *result) = 0;
  virtual STDCALL HRESULT createElementNS(BSTR namespaceURI, 
		                      BSTR qualifiedName,
				      IDOMElementPtr *result) = 0;
  virtual STDCALL HRESULT createAttributeNS(BSTR namespaceURI, 
		                      BSTR qualifiedName,
				      IDOMAttributePtr *result) = 0;
  virtual STDCALL HRESULT getElementsByTagNameNS(BSTR namespaceURI, 
		                      BSTR localName,
				      IDOMNodeListPtr *result) = 0;
  virtual STDCALL HRESULT getElementsById(BSTR elementId, 
				      IDOMElementPtr *result) = 0;
};


extern "C" {

#ifdef LINUX
void STDCALL GetDOMImplementation(IDOMImplementationPtr *result);
#else
void STDCALL __declspec(dllexport) GetDOMImplementation(IDOMImplementationPtr *result);
#endif

};
#endif
