/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtSddbDataElements_hpp)
#define BtSddbDataElements_hpp

#include <Bluetooth/BtTypes.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations
    ------------------------------------------------------------------------ */

class BtSddbDataElement;

class BtSddbDataElementFactory
{
    public:

        static BtSddbDataElementFactory& GetInstance();

    public:
        virtual ~BtSddbDataElementFactory();


        BtSddbDataElement* NewDataElement(UINT8 data_element_descriptor);

    protected:

        BtSddbDataElement* NewUint(UINT8 size_descriptor);


        BtSddbDataElement* NewSint(UINT8 size_descriptor);


        BtSddbDataElement* NewUuid(UINT8 size_descriptor);

    private:
        BtSddbDataElementFactory();

    private:
        static BtSddbDataElementFactory m_factory;
};

/*  ------------------------------------------------------------------------
    Forward deklarations for friend declaration
    ------------------------------------------------------------------------ */

class BtSddbServiceAttribute;
class BtSddbDeContainer;

class BtSddbDataElement
{
    public:
        BtSddbDataElement();

        virtual ~BtSddbDataElement();


        virtual BtDataElementType GetType() const = 0;


        virtual INT32 GetSize() const = 0;


        virtual BOOLEAN IsValid() const = 0;

    protected:

        virtual BtSddbDataElement* Clone() const = 0;


        virtual INT32 GetMemorySize() const = 0;


        virtual BOOLEAN ReadFromMemory(const void*& memory, INT32& memory_size) = 0;


        virtual void* WriteToMemory(void* memory) const = 0;

    private:
        friend class BtSddbServiceAttribute;
        friend class BtSddbDeContainer;
};


class BtSddbDeOneByteDescriptionType: public BtSddbDataElement
{
    private:
        typedef BtSddbDataElement Base;

    public:
        BtSddbDeOneByteDescriptionType();

        virtual ~BtSddbDeOneByteDescriptionType();


        void* GetData();


        const void* GetData() const;

    protected:

        virtual INT32 GetMemorySize() const;


        virtual BOOLEAN ReadFromMemory(const void*& memory, INT32& memory_size);

        virtual void* WriteToMemory(void* memory) const;


        void SetData(void* data);


        virtual UINT8 GetDataElementDescriptor() const = 0;

    protected:
        void* m_data;
};


class BtSddbDeBaseCType: public BtSddbDeOneByteDescriptionType
{
    private:
        typedef BtSddbDeOneByteDescriptionType Base;

    public:
        BtSddbDeBaseCType();

        virtual ~BtSddbDeBaseCType();


        virtual BOOLEAN IsValid() const;
};

class BtSddbDeNil: public BtSddbDeBaseCType
{
    private:
        typedef BtSddbDeBaseCType Base;

    public:
        BtSddbDeNil();

        virtual ~BtSddbDeNil();


        virtual BtDataElementType GetType() const;


        virtual INT32 GetSize() const;

    protected:

        virtual BtSddbDataElement* Clone() const;


        virtual UINT8 GetDataElementDescriptor() const;
};

class BtSddbDeUintBase: public BtSddbDeBaseCType
{
    private:
        typedef BtSddbDeBaseCType Base;

    public:
        BtSddbDeUintBase();

        virtual ~BtSddbDeUintBase();


        virtual BtDataElementType GetType() const;
};

class BtSddbDeUint8: public BtSddbDeUintBase
{
    private:
        typedef BtSddbDeUintBase Base;

    public:
        BtSddbDeUint8(UINT8 value = 0);

        virtual ~BtSddbDeUint8();


        virtual INT32 GetSize() const;


        UINT8 GetValue() const;


        void SetValue(UINT8 value);

    protected:

        virtual BtSddbDataElement* Clone() const;


        virtual UINT8 GetDataElementDescriptor() const;

    private:
        UINT8 m_value;
};

class BtSddbDeUint16: public BtSddbDeUintBase
{
    private:
        typedef BtSddbDeUintBase Base;

    public:
        BtSddbDeUint16(UINT16 value = 0);

        virtual ~BtSddbDeUint16();


        virtual INT32 GetSize() const;


        UINT16 GetValue() const;


        void SetValue(UINT16 value);

    protected:

        virtual BtSddbDataElement* Clone() const;


        virtual UINT8 GetDataElementDescriptor() const;

    private:
        UINT8 m_value[2];
};

class BtSddbDeUint32: public BtSddbDeUintBase
{
    private:
        typedef BtSddbDeUintBase Base;

    public:
        BtSddbDeUint32(UINT32 value = 0);

        virtual ~BtSddbDeUint32();


        virtual INT32 GetSize() const;


        UINT32 GetValue() const;


        void SetValue(UINT32 value);

    protected:

        virtual BtSddbDataElement* Clone() const;


        virtual UINT8 GetDataElementDescriptor() const;

    private:
        UINT8 m_value[4];
};

class BtSddbDeSintBase: public BtSddbDeBaseCType
{
    private:
        typedef BtSddbDeBaseCType Base;

    public:
        BtSddbDeSintBase();

        virtual ~BtSddbDeSintBase();


        virtual BtDataElementType GetType() const;
};

class BtSddbDeSint8: public BtSddbDeSintBase
{
    private:
        typedef BtSddbDeSintBase Base;

    public:
        BtSddbDeSint8(INT8 value = 0);

        virtual ~BtSddbDeSint8();


        virtual INT32 GetSize() const;


        INT8 GetValue() const;


        void SetValue(INT8 value);

    protected:

        virtual BtSddbDataElement* Clone() const;


        virtual UINT8 GetDataElementDescriptor() const;

    private:
        UINT8 m_value;
};

class BtSddbDeSint16: public BtSddbDeSintBase
{
    private:
        typedef BtSddbDeSintBase Base;

    public:
        BtSddbDeSint16(INT16 value = 0);

        virtual ~BtSddbDeSint16();


        virtual INT32 GetSize() const;


        INT16 GetValue() const;


        void SetValue(INT16 value);

    protected:

        virtual BtSddbDataElement* Clone() const;


        virtual UINT8 GetDataElementDescriptor() const;

    private:
        UINT8 m_value[2];
};

class BtSddbDeSint32: public BtSddbDeSintBase
{
    private:
        typedef BtSddbDeSintBase Base;

    public:
        BtSddbDeSint32(INT32 value = 0);

        virtual ~BtSddbDeSint32();


        virtual INT32 GetSize() const;


        INT32 GetValue() const;


        void SetValue(INT32 value);

    protected:

        virtual BtSddbDataElement* Clone() const;


        virtual UINT8 GetDataElementDescriptor() const;

    private:
        UINT8 m_value[4];
};

class BtSddbDeUuidBase: public BtSddbDeBaseCType
{
    private:
        typedef BtSddbDeBaseCType Base;

    public:
        BtSddbDeUuidBase();

        virtual ~BtSddbDeUuidBase();


        virtual BtDataElementType GetType() const;
};

class BtSddbDeUuid16: public BtSddbDeUuidBase
{
    private:
        typedef BtSddbDeUuidBase Base;

    public:
        BtSddbDeUuid16(UINT16 value = 0);

        virtual ~BtSddbDeUuid16();


        virtual INT32 GetSize() const;


        UINT16 GetValue() const;


        void SetValue(UINT16 value);

    protected:

        virtual BtSddbDataElement* Clone() const;


        virtual UINT8 GetDataElementDescriptor() const;

    private:
        UINT8 m_value[2];
};

class BtSddbDeUuid32: public BtSddbDeUuidBase
{
    private:
        typedef BtSddbDeUuidBase Base;

    public:
        BtSddbDeUuid32(UINT32 value = 0);

        virtual ~BtSddbDeUuid32();


        virtual INT32 GetSize() const;


        UINT32 GetValue() const;


        void SetValue(UINT32 value);

    protected:

        virtual BtSddbDataElement* Clone() const;


        virtual UINT8 GetDataElementDescriptor() const;

    private:
        UINT8 m_value[4];
};

class BtSddbDeBoolean: public BtSddbDeBaseCType
{
    private:
        typedef BtSddbDeBaseCType Base;

    public:
        BtSddbDeBoolean(BOOLEAN value = FALSE);

        virtual ~BtSddbDeBoolean();


        virtual BtDataElementType GetType() const;


        virtual INT32 GetSize() const;


        BOOLEAN GetValue() const;


        void SetValue(BOOLEAN value);

    protected:

        virtual BtSddbDataElement* Clone() const;


        virtual UINT8 GetDataElementDescriptor() const;

    private:
        BOOLEAN m_value;
};

class BtSddbDeByteBlockType: public BtSddbDeOneByteDescriptionType
{
    private:
        typedef BtSddbDeOneByteDescriptionType Base;

    public:
        BtSddbDeByteBlockType();

        virtual ~BtSddbDeByteBlockType();


        virtual BOOLEAN IsValid() const;


        UINT8* GetValue() const;


        void SetValue(const UINT8* value);
};

class BtSddbDeBigUintBase: public BtSddbDeByteBlockType
{
    private:
        typedef BtSddbDeByteBlockType Base;

    public:
        BtSddbDeBigUintBase();

        virtual ~BtSddbDeBigUintBase();


        virtual BtDataElementType GetType() const;
};

class BtSddbDeUint64: public BtSddbDeBigUintBase
{
    private:
        typedef BtSddbDeBigUintBase Base;

    public:
        BtSddbDeUint64(const UINT8* value = 0);

        virtual ~BtSddbDeUint64();


        virtual INT32 GetSize() const;

    protected:

        virtual BtSddbDataElement* Clone() const;


        virtual UINT8 GetDataElementDescriptor() const;

    private:
        UINT8 m_value[8];
};

class BtSddbDeUint128: public BtSddbDeBigUintBase
{
    private:
        typedef BtSddbDeBigUintBase Base;

    public:
        BtSddbDeUint128(const UINT8* value = 0);

        virtual ~BtSddbDeUint128();


        virtual INT32 GetSize() const;

    protected:

        virtual BtSddbDataElement* Clone() const;


        virtual UINT8 GetDataElementDescriptor() const;

    private:
        UINT8 m_value[16];
};

class BtSddbDeBigSintBase: public BtSddbDeByteBlockType
{
    private:
        typedef BtSddbDeByteBlockType Base;

    public:
        BtSddbDeBigSintBase();

        virtual ~BtSddbDeBigSintBase();


        virtual BtDataElementType GetType() const;
};

class BtSddbDeSint64: public BtSddbDeBigUintBase
{
    private:
        typedef BtSddbDeBigUintBase Base;

    public:
        BtSddbDeSint64(const UINT8* value = 0);

        virtual ~BtSddbDeSint64();


        virtual INT32 GetSize() const;

    protected:

        virtual BtSddbDataElement* Clone() const;


        virtual UINT8 GetDataElementDescriptor() const;

    private:
        UINT8 m_value[8];
};

class BtSddbDeSint128: public BtSddbDeBigUintBase
{
    private:
        typedef BtSddbDeBigUintBase Base;

    public:
        BtSddbDeSint128(const UINT8* value = 0);

        virtual ~BtSddbDeSint128();


        virtual INT32 GetSize() const;

    protected:

        virtual BtSddbDataElement* Clone() const;


        virtual UINT8 GetDataElementDescriptor() const;

    private:
        UINT8 m_value[16];
};

class BtSddbDeUuid128: public BtSddbDeByteBlockType
{
    private:
        typedef BtSddbDeByteBlockType Base;

    public:
        BtSddbDeUuid128(const UINT8* value = 0);

        virtual ~BtSddbDeUuid128();


        virtual BtDataElementType GetType() const;


        virtual INT32 GetSize() const;

    protected:

        virtual BtSddbDataElement* Clone() const;


        virtual UINT8 GetDataElementDescriptor() const;

    private:
        UINT8 m_value[16];
};

class BtSddbDeVariableLengthType: public BtSddbDataElement
{
    private:
        typedef BtSddbDataElement Base;

    public:
        BtSddbDeVariableLengthType();

        BtSddbDeVariableLengthType(const WString& value);

        virtual ~BtSddbDeVariableLengthType();


        virtual INT32 GetSize() const;


        virtual BOOLEAN IsValid() const;


        WString GetValue() const;


        void SetValue(const WString& value);

    protected:

        virtual INT32 GetMemorySize() const;


        virtual BOOLEAN ReadFromMemory(const void*& memory, INT32& memory_size);


        virtual void* WriteToMemory(void* memory) const;


        virtual UINT8 GetDataElementTypeDescriptor() const = 0;


        UINT8 GetDataElementSizeDescriptor() const;

    protected:
        String m_value;
};

class BtSddbDeString: public BtSddbDeVariableLengthType
{
    private:
        typedef BtSddbDeVariableLengthType Base;

    public:
        BtSddbDeString();

        BtSddbDeString(const WString& value);

        virtual ~BtSddbDeString();


        virtual BtDataElementType GetType() const;

    protected:

        virtual BtSddbDataElement* Clone() const;


        virtual UINT8 GetDataElementTypeDescriptor() const;
};

class BtSddbDeUrl: public BtSddbDeVariableLengthType
{
    private:
        typedef BtSddbDeVariableLengthType Base;

    public:
        BtSddbDeUrl(const WString& value);

        BtSddbDeUrl();

        virtual ~BtSddbDeUrl();


        virtual BtDataElementType GetType() const;

    protected:

        virtual BtSddbDataElement* Clone() const;


        virtual UINT8 GetDataElementTypeDescriptor() const;
};

class BtSddbDeContainer: public BtSddbDataElement
{
    private:
        typedef BtSddbDataElement Base;

    public:
        BtSddbDeContainer();

        virtual ~BtSddbDeContainer();


        virtual INT32 GetSize() const;


        virtual BOOLEAN IsValid() const;


        BtSddbDataElement* GetFirst();


        const BtSddbDataElement* GetFirst() const;


        BtSddbDataElement* GetNext(const BtSddbDataElement* current);


        const BtSddbDataElement* GetNext(const BtSddbDataElement* current) const;


        BOOLEAN Insert(const BtSddbDataElement& data_element, const BtSddbDataElement* position = 0);


        BtSddbDataElement* Delete(const BtSddbDataElement* data_element);


        void Clear(void);

    protected:

        virtual INT32 GetMemorySize() const;


        INT32 GetMemorySizeOfContainedDataElements() const;


        virtual BOOLEAN ReadFromMemory(const void*& memory, INT32& memory_size);


        virtual void* WriteToMemory(void* memory) const;


        virtual UINT8 GetDataElementTypeDescriptor() const = 0;


        UINT8 GetDataElementSizeDescriptor() const;


        BOOLEAN Copy(const BtSddbDeContainer* to_copy);

    private:
        class BtSddbDeContainerNode
        {
            public:
                BtSddbDeContainerNode(BtSddbDataElement* data_element, BtSddbDeContainerNode* next = 0);

                virtual ~BtSddbDeContainerNode();


                BtSddbDataElement* GetDataElement();

                void SetDataElement(BtSddbDataElement* data_element);

                BtSddbDeContainerNode* GetNext();

                void SetNext(BtSddbDeContainerNode* next);

            private:
                BtSddbDataElement* m_data_element;


                BtSddbDeContainerNode* m_next;
        };

    private:

        BtSddbDeContainerNode* CreateNewContainerNode(const BtSddbDataElement* data_element);


        BtSddbDeContainerNode* Search(const BtSddbDataElement* data_element) const;

    private:
        BOOLEAN m_is_valid;

        BtSddbDeContainerNode* m_anchor;

        INT32 m_number_of_nodes;
};

class BtSddbDeSequence: public BtSddbDeContainer
{
    private:
        typedef BtSddbDeContainer Base;

    public:
        BtSddbDeSequence();

        virtual ~BtSddbDeSequence();


        virtual BtDataElementType GetType() const;

    protected:

        virtual BtSddbDataElement* Clone() const;


        virtual UINT8 GetDataElementTypeDescriptor() const;
};

class BtSddbDeAlternative: public BtSddbDeContainer
{
    private:
        typedef BtSddbDeContainer Base;

    public:
        BtSddbDeAlternative();

        virtual ~BtSddbDeAlternative();


        virtual BtDataElementType GetType() const;

    protected:

        virtual BtSddbDataElement* Clone() const;


        virtual UINT8 GetDataElementTypeDescriptor() const;
};

#endif  // BtSddbDataElements_hpp

