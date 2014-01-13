//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#ifndef IP2CountryH
#define IP2CountryH
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class clsIpP2Country {
private:
    uint32_t ui32Size, ui32IPv6Size;
    uint32_t * ui32RangeFrom, * ui32RangeTo;
    uint8_t * ui8RangeCI, * ui8IPv6RangeCI;
    uint8_t * ui128IPv6RangeFrom, * ui128IPv6RangeTo;

    void LoadIPv4();
    void LoadIPv6();
public:
    static clsIpP2Country * mPtr;

    uint32_t ui32Count, ui32IPv6Count;

	clsIpP2Country();
	~clsIpP2Country();

	const char * Find(const uint8_t * ui128IpHash, const bool &bCountryName);
	uint8_t Find(const uint8_t * ui128IpHash);

    static const char * GetCountry(const uint8_t &ui8dx, const bool &bCountryName);

    void Reload();
};
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#endif
