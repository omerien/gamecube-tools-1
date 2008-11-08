#ifndef __PARSER_H__
#define __PARSER_H__

class CTokenString;

using namespace std;

class CParser
{
public:
	struct _ttokenstringlist {
	public:
		_ttokenstringlist(const char *pszTokenString,int nLen);
		~_ttokenstringlist();

		const char* GetTokenValue(const char *pszTokenName,const char *pszDefault = NULL) const;

		int nTokens;
		CTokenString *pToken;
		_ttokenstringlist *pNext;
	};

public:
	CParser();
	virtual ~CParser();

	int Parse(int argc,const char **argv);

	void ReleaseAll();

	int GetOutputFileType() {return m_nOutType;}
	const char* GetOutputFilename() {return m_sOutFilename.c_str();}
	const _ttokenstringlist* GetEntries() {return m_pArgList;}

protected:
	void Empty();
	int LoadScriptfile(const char *pszFilename);
	int LoadBuffer(char *pBuffer,int nLen);
	int NewTokenString(const char *pszTokenString,int nLen);

protected:
	int m_nOutType;
	string m_sOutFilename;
	string m_sInFilename;

	_ttokenstringlist *m_pArgList;
};

#endif
