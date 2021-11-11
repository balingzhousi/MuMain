// MultiLanguage.h: interface for the CMultiLanguage class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MULTILANGUAGE_H__01D5F840_67B5_4472_B89F_9C3EAF89107A__INCLUDED_)
#define AFX_MULTILANGUAGE_H__01D5F840_67B5_4472_B89F_9C3EAF89107A__INCLUDED_

#pragma once

#ifdef LJH_ADD_SUPPORTING_MULTI_LANGUAGE

class CMultiLanguage
{

private:
	static CMultiLanguage *ms_Singleton;

	BYTE byLanguage;
	int iCodePage;
	int iNumByteForOneCharUTF8;

	CMultiLanguage()	{ ms_Singleton = this; };				

public:
	CMultiLanguage(std::string strSelectedML);
	~CMultiLanguage()	{ ms_Singleton = 0; };

	BYTE GetLanguage();				// Getters
	int GetCodePage();
	int GetNumByteForOneCharUTF8();

	BOOL IsCharUTF8(const char* pszText);
	int	 ConvertCharToWideStr(std::wstring& wstrDest, LPCSTR lpString);
	int  ConvertWideCharToStr(std::string& strDest, LPCWSTR lpwString, int iConversionType = CP_UTF8);
	void ConvertANSIToUTF8OrViceVersa(std::string& strDest, LPCSTR lpString);
	int	 GetClosestBlankFromCenter(const std::wstring wstrTarget);
	
	WPARAM ConvertFulltoHalfWidthChar(DWORD wParam);
	// wrapper functions 
	// WIN32 APIs
	// MSDN������ GetTextExtentPoint���� �� ��Ȯ�� ����� �����ϴ� GetTextExtentPoint32 ����� ������ �����Ѵ�.
	BOOL _GetTextExtentPoint32(HDC hdc, LPCWSTR lpString, int cbString, LPSIZE lpSize);
	BOOL _GetTextExtentPoint32(HDC hdc, LPCSTR lpString, int cbString, LPSIZE lpSize);

	BOOL _TextOut(HDC hdc, int nXStart, int nYStart, LPCWSTR lpString, int cbString);
	BOOL _TextOut(HDC hdc, int nXStart, int nYStart, LPCSTR lpString, int cbString);
	
	static CMultiLanguage* GetSingletonPtr() { return ms_Singleton; };
};
#endif //LJH_ADD_SUPPORTING_MULTI_LANGUAGE
#endif // !defined(AFX_MULTILANGUAGE_H__01D5F840_67B5_4472_B89F_9C3EAF89107A__INCLUDED_)