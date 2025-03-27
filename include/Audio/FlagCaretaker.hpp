#ifndef FlagCaretaker_hpp
#define FlagCaretaker_hpp


class FlagCaretaker {
public:
    FlagCaretaker(BOOLEAN &flag, BOOLEAN value_to_set);
    ~FlagCaretaker();
private:
    BOOLEAN &m_flag;
    BOOLEAN m_value_to_set;
};

#endif


