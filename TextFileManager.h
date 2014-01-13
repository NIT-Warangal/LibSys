//

//---------------------------------------------------------------------------
#ifndef TextFileManagerH
#define TextFileManagerH
//---------------------------------------------------------------------------
struct User;
//---------------------------------------------------------------------------

class clsTextFilesManager {
private:
    struct TextFile {
        ~TextFile();

        char * sCommand, * sText;
        TextFile * prev, * next;
    };

    TextFile * TextFiles;
public:
    static clsTextFilesManager * mPtr;

	clsTextFilesManager();
	~clsTextFilesManager();

	bool ProcessTextFilesCmd(User * u, char * cmd, bool fromPM = false) const;
	void RefreshTextFiles();
};
//---------------------------------------------------------------------------

#endif
