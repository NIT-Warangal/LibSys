//

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#ifndef PXBReaderH
#define PXBReaderH
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class PXBReader {
private:
    bool bFullRead;

    char * sActualPosition;

    FILE * pFile;

    size_t szRemainingSize;

    void ReadNextFilePart();
public:
    enum enmDataTypes {
        PXB_BYTE,
        PXB_TWO_BYTES,
        PXB_FOUR_BYTES,
        PXB_STRING
    };

    void * pItemDatas[10];

    uint16_t ui16ItemLengths[10];

    char sItemIdentifiers[10][2];

    uint8_t ui8ItemValues[10];

	PXBReader();
	~PXBReader();

    bool OpenFileRead(const char * sFilename);
    bool ReadNextItem(const uint16_t * sExpectedIdentificators, const uint8_t &ui8ExpectedSubItems, const uint8_t &ui8ExtraSubItems = 0);

    bool OpenFileSave(const char * sFilename);
    bool WriteNextItem(const uint32_t &ui32Length, const uint8_t &ui8SubItems);
    void WriteRemaining();
};
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#endif
