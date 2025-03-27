
#if !defined(FmRadio_SelectStrongerFreq_hpp)
#define FmRadio_SelectStrongerFreq_hpp

#include <Atl/Gui/AtlItemListWindow.hpp>
#include <Atl/Features/ProviderProxyContainer.hpp>

class FmRadioSelectStrongerFreq : public AtlItemListWindow {
    typedef AtlItemListWindow Base;

    public:
        FmRadioSelectStrongerFreq();
        ~FmRadioSelectStrongerFreq();
        void Init(Provider *fmradio_stat_prov);

    protected:
        BOOLEAN OnConfirm();

        BOOLEAN OnCancel();

        void OnOpen();

    private:
        ProviderProxyContainer  m_fmradio_stat_cont;
        NotEqualsRule           m_rule;
        FilterProvider          m_fmradio_stat_filtered_prov;
};

#endif  // FmRadio_SelectStrongerFreq_hpp
