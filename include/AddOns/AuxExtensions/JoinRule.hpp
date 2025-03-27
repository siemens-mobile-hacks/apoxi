/* =============================================================================
** Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
** =============================================================================
**
** =============================================================================
**
** This document contains proprietary information belonging to COMNEON.
** Passing on and copying of this document, use and communication of its
** contents is not permitted without prior written authorisation.
**
** =============================================================================
*/

#if ! defined(Apoxi_AuxExtensions_JoinJoinRule_hpp)
#define Apoxi_AuxExtensions_JoinJoinRule_hpp

#include <Auxiliary/PhoneNumber.hpp>

class DataItem; //lint !e763

class JoinRule
{
    public:

        enum RelationType {
            Injective,
            Surjective,
            Bijective,
            Cartesian
        };

        JoinRule();
        virtual ~JoinRule();

        virtual BOOLEAN ExecuteRule(const DataItem& fst_item, const DataItem& snd_item) = 0;

        virtual JoinRule::RelationType GetType() = 0;
};

class StandardJoinRule : public JoinRule
{
    typedef JoinRule Base;
    public:

        enum ComparisonType {
            EqualType,
            NotEqualType,
            LessType,
            NotLessType,
            GreaterType,
            NotGreaterType,
            CartesianType
        };

        StandardJoinRule();
        virtual ~StandardJoinRule();
        void Init (ComparisonType type);

        virtual BOOLEAN ExecuteRule(const DataItem& fst_item, const DataItem& snd_item);
        virtual JoinRule::RelationType GetType();

    private:
        ComparisonType m_type;
};

class PhoneNumberJoinRule : public JoinRule
{
    typedef JoinRule Base;
    public:
        PhoneNumberJoinRule();
        virtual ~PhoneNumberJoinRule();
        virtual BOOLEAN ExecuteRule(const DataItem& fst_item, const DataItem& snd_item);
        virtual BOOLEAN MatchPhoneNumbers(const PhoneNumber& number1, const PhoneNumber& number2);
        virtual JoinRule::RelationType GetType();
};

#endif  // Apoxi_AuxExtensions_JoinJoinRule_hpp


