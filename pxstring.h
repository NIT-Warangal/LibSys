//

//------------------------------------------------------------------------------
#ifndef pxstringh
#define pxstringh
//------------------------------------------------------------------------------

class string {
private:
	char * sData;
	size_t szDataLen;

	void stralloc(const char * sTxt, const size_t &szLen);
    string(const string & sStr1, const string & sStr2);
    string(const char * sTxt, const string & sStr);
    string(const string & sStr, const char * sTxt);
public:
    string();
	string(const char * sTxt);
	string(const char * sTxt, const size_t &szLen);
	string(const string & sStr);
	string(const uint32_t & ui32Number);
	string(const int32_t & i32Number);
	string(const uint64_t & ui64Number);
	string(const int64_t & i64Number);

    ~string();

    size_t size() const;
	char * c_str() const;
	void clear();

	string operator+(const char * sTxt) const;
	string operator+(const string & sStr) const;
	friend string operator+(const char * sTxt, const string & sStr);

	string & operator+=(const char * sTxt);
	string & operator+=(const string & sStr);

    string & operator=(const char * sTxt);
    string & operator=(const string & sStr);

	bool operator==(const char * sTxt);
	bool operator==(const string & sStr);
};
//------------------------------------------------------------------------------

#endif
