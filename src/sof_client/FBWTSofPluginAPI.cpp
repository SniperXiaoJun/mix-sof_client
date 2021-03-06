/**********************************************************\

  Auto-generated FBWTSofPluginAPI.cpp

\**********************************************************/

#include "sof_client-tools.h"

#include "modp_b64.h"

#include "FBWTSofPluginAPI.h"

#include "FILE_LOG.h"

static std::string mix_b64_encode(std::string s)
{
	std::string x(modp_b64_encode_len(s.size()), '\0');
	size_t d = modp_b64_encode(const_cast<char*>(x.data()), s.data(), (int)s.size());
	x.erase(d, std::string::npos);
	s.swap(x);
	return s;
}

/**
 * base 64 decode a string (self-modifing)
 * On failure, the string is empty.
 *
 * This function is for C++ only (duh)
 *
 * \param[in,out] s the string to be decoded
 * \return a reference to the input string
 */
static std::string mix_b64_decode(std::string s)
{
	std::string x(modp_b64_decode_len(s.size()), '\0');
	size_t d = modp_b64_decode(const_cast<char*>(x.data()), s.data(), (int)s.size());
	if (d == MODP_B64_ERROR) {
		x.clear();
	}
	else {
		x.erase(d, std::string::npos);
	}
	s.swap(x);
	return s;
}



// Read/Write property testString
std::string FBWTSofPluginAPI::get_testString()
{
	return m_testString;
}

void FBWTSofPluginAPI::set_testString(const std::string& val)
{
	m_testString = val;
}


std::string FBWTSofPluginAPI::FunTestString()
{
	std::string strResult = "FunTestString ok!";

	return strResult;
}

std::string FBWTSofPluginAPI::SOF_GetVersion()
{
	std::string strResult;

	VERSION version;

	char data_info_value[1024] = { 0 };
	int data_info_len = sizeof(data_info_value);

	if (NULL == ckpFunctions)
	{
		ulResult = ::SOF_InitializeLibraryNative("WTSKFInterface.dll", &ckpFunctions);
		if (SOR_OK != ulResult)
		{
			goto end;
		}
		this->SOF_GetDefaultContainer();
	}

	ulResult = ::SOF_GetVersion(ckpFunctions, &version);
	if (SOR_OK != ulResult)
	{
		goto end;
	}

	sprintf(data_info_value, "%d.%d", version.major, version.minor);
	data_info_len = strlen(data_info_value);

	strResult = std::string(data_info_value, data_info_value + data_info_len);
end:
	return strResult;
}

ULONG FBWTSofPluginAPI::SOF_SetSignMethod(ULONG ulMethod)
{
	if (NULL == ckpFunctions)
	{
		ulResult = ::SOF_InitializeLibraryNative("WTSKFInterface.dll", &ckpFunctions);
		if (SOR_OK != ulResult)
		{
			goto end;
		}
		this->SOF_GetDefaultContainer();
	}

	ulResult = ::SOF_SetSignMethod(ckpFunctions, ulMethod);
	if (SOR_OK != ulResult)
	{
		goto end;
	}

end:
	return ulResult;
}

ULONG FBWTSofPluginAPI::SOF_GetSignMethod()
{
	ULONG ulMethod;

	if (NULL == ckpFunctions)
	{
		ulResult = ::SOF_InitializeLibraryNative("WTSKFInterface.dll", &ckpFunctions);
		if (SOR_OK != ulResult)
		{
			goto end;
		}
		this->SOF_GetDefaultContainer();
	}

	ulResult = ::SOF_GetSignMethod(ckpFunctions, &ulMethod);
	if (SOR_OK != ulResult)
	{
		goto end;
	}

end:
	return ulMethod;
}

ULONG FBWTSofPluginAPI::SOF_SetEncryptMethod(ULONG ulMethod)
{
	if (NULL == ckpFunctions)
	{
		ulResult = ::SOF_InitializeLibraryNative("WTSKFInterface.dll", &ckpFunctions);
		if (SOR_OK != ulResult)
		{
			goto end;
		}
		this->SOF_GetDefaultContainer();
	}

	ulResult = ::SOF_SetEncryptMethod(ckpFunctions, ulMethod);
	if (SOR_OK != ulResult)
	{
		goto end;
	}

end:
	return ulResult;
}

ULONG FBWTSofPluginAPI::SOF_GetEncryptMethod()
{
	ULONG ulMethod;

	if (NULL == ckpFunctions)
	{
		ulResult = ::SOF_InitializeLibraryNative("WTSKFInterface.dll", &ckpFunctions);
		if (SOR_OK != ulResult)
		{
			goto end;
		}
		this->SOF_GetDefaultContainer();
	}

	ulResult = ::SOF_GetEncryptMethod(ckpFunctions, &ulMethod);
	if (SOR_OK != ulResult)
	{
		goto end;
	}

end:
	return ulMethod;
}

std::string FBWTSofPluginAPI::SOF_GetUserList()
{
	std::string strResult;
	BYTE data_info_value[1024] = { 0 };
	ULONG data_info_len = sizeof(data_info_value);

	if (NULL == ckpFunctions)
	{
		ulResult = ::SOF_InitializeLibraryNative("WTSKFInterface.dll", &ckpFunctions);
		if (SOR_OK != ulResult)
		{
			goto end;
		}
		this->SOF_GetDefaultContainer();
	}

	ulResult = ::SOF_GetUserList(ckpFunctions, data_info_value, &data_info_len);
	if (SOR_OK != ulResult)
	{
		goto end;
	}

	strResult = std::string(data_info_value, data_info_value + data_info_len);
end:

	return strResult;
}

std::string FBWTSofPluginAPI::SOF_ExportUserCert(std::string strContainerName)
{
	std::string strResult;
	BYTE data_info_value[1024 * 4] = { 0 };
	ULONG data_info_len = sizeof(data_info_value);

	if (NULL == ckpFunctions)
	{
		ulResult = ::SOF_InitializeLibraryNative("WTSKFInterface.dll", &ckpFunctions);
		if (SOR_OK != ulResult)
		{
			goto end;
		}
		this->SOF_GetDefaultContainer();
	}
	if ((strContainerName.size() == 0) || (strContainerName == "")) strContainerName = m_default_container;

	ulResult = ::SOF_ExportUserCert(ckpFunctions, (LPSTR)strContainerName.c_str(), data_info_value, &data_info_len);
	if (SOR_OK != ulResult)
	{
		goto end;
	}

	strResult = std::string(data_info_value, data_info_value + data_info_len);
	strResult = mix_b64_encode(strResult);
end:

	return strResult;
}

#ifndef WINAPI
#define WINAPI __stdcall
#endif

typedef int(WINAPI* PFGetPasswordDlg)(int, char*, int *);


BOOL FBWTSofPluginAPI::SOF_Login(std::string strContainerName, std::string strPIN)
{
	void *		g_hUI = NULL;
	PFGetPasswordDlg  GetPasswordDlg = NULL;

	if (NULL == ckpFunctions)
	{
		ulResult = ::SOF_InitializeLibraryNative("WTSKFInterface.dll", &ckpFunctions);
		if (SOR_OK != ulResult)
		{
			goto end;
		}
		this->SOF_GetDefaultContainer();
	}
	if ((strContainerName.size() == 0) || (strContainerName == "")) strContainerName = m_default_container;


	if ((strPIN.size() == 0) || (strPIN == ""))
	{
		unsigned int siRet = 0;
		int nPWDLen = 0;
		char szPwd[64] = { 0 };

		FILE_LOG_FMT(file_log_name, "%s %d watch = %d", __FUNCTION__, __LINE__, g_hUI);

		if (g_hUI == NULL)
		{
			g_hUI = MYLoadLibrary("resui.dll");
			if (g_hUI == NULL)
			{
				ulResult = SOR_UNKNOWNERR;
				goto end;
			}
		}

		FILE_LOG_FMT(file_log_name, "%s %d watch = %d", __FUNCTION__, __LINE__, g_hUI);

		if (NULL == GetPasswordDlg)
		{
			GetPasswordDlg = (PFGetPasswordDlg)MYGetProcAddress(g_hUI, "GetPasswordDlg");
			if (NULL == GetPasswordDlg)
			{
				ulResult = SOR_UNKNOWNERR;
				goto end;
			}
		}

		FILE_LOG_FMT(file_log_name, "%s %d watch = %d", __FUNCTION__, __LINE__, GetPasswordDlg);

		nPWDLen = sizeof(szPwd);
		//memset(g_szPwd, 0, sizeof(g_szPwd));
		memset(szPwd, 0, sizeof(szPwd));
		siRet = GetPasswordDlg(0, szPwd, &nPWDLen);
		if (1 != siRet)
		{
			ulResult = SOR_UNKNOWNERR;
			goto end;
		}

		FILE_LOG_FMT(file_log_name, "%s %d watch = %d", __FUNCTION__, __LINE__, siRet);

		strPIN = szPwd;

		FILE_LOG_FMT(file_log_name, "%s %d watch = %s", __FUNCTION__, __LINE__, szPwd);

		if (g_hUI)
		{
			MYFreeLibrary(g_hUI);
			g_hUI = NULL;
			GetPasswordDlg = NULL;
		}
	}

	ulResult = ::SOF_Login(ckpFunctions, (LPSTR)strContainerName.c_str(), (LPSTR)strPIN.c_str());
	if (SOR_OK != ulResult)
	{
		goto end;
	}

end:
	return !ulResult;
}

ULONG FBWTSofPluginAPI::SOF_GetPinRetryCount(std::string strContainerName)
{
	ULONG ulRetry;

	if (NULL == ckpFunctions)
	{
		ulResult = ::SOF_InitializeLibraryNative("WTSKFInterface.dll", &ckpFunctions);
		if (SOR_OK != ulResult)
		{
			goto end;
		}
		this->SOF_GetDefaultContainer();
	}
	if ((strContainerName.size() == 0) || (strContainerName == "")) strContainerName = m_default_container;

	ulResult = ::SOF_GetPinRetryCount(ckpFunctions, (LPSTR)strContainerName.c_str(), &ulRetry);
	if (SOR_OK != ulResult)
	{
		goto end;
	}

end:

	return ulRetry;
}

BOOL FBWTSofPluginAPI::SOF_ChangePassWd(std::string strContainerName, std::string strPINOld, std::string strPINNew)
{
	if (NULL == ckpFunctions)
	{
		ulResult = ::SOF_InitializeLibraryNative("WTSKFInterface.dll", &ckpFunctions);
		if (SOR_OK != ulResult)
		{
			goto end;
		}
		this->SOF_GetDefaultContainer();
	}
	if ((strContainerName.size() == 0) || (strContainerName == "")) strContainerName = m_default_container;

	ulResult = ::SOF_ChangePassWd(ckpFunctions, (LPSTR)strContainerName.c_str(), (LPSTR)strPINOld.c_str(), (LPSTR)strPINNew.c_str());
	if (SOR_OK != ulResult)
	{
		goto end;
	}

end:
	return !ulResult;
}

std::string FBWTSofPluginAPI::SOF_ExportExChangeUserCert(std::string strContainerName)
{
	std::string strResult;
	BYTE data_info_value[1024 * 4] = { 0 };
	ULONG data_info_len = sizeof(data_info_value);

	if (NULL == ckpFunctions)
	{
		ulResult = ::SOF_InitializeLibraryNative("WTSKFInterface.dll", &ckpFunctions);
		if (SOR_OK != ulResult)
		{
			goto end;
		}
		this->SOF_GetDefaultContainer();
	}
	if ((strContainerName.size() == 0) || (strContainerName == "")) strContainerName = m_default_container;

	ulResult = ::SOF_ExportExChangeUserCert(ckpFunctions, (LPSTR)strContainerName.c_str(), data_info_value, &data_info_len);
	if (SOR_OK != ulResult)
	{
		goto end;
	}

	strResult = std::string(data_info_value, data_info_value + data_info_len);
	strResult = mix_b64_encode(strResult);

end:

	return strResult;
}

std::string FBWTSofPluginAPI::SOF_GetCertInfo(std::string strCert, UINT16 u16Type)
{
	std::string strResult;
	BYTE data_info_value[1024 * 4] = { 0 };
	ULONG data_info_len = sizeof(data_info_value);

	if (NULL == ckpFunctions)
	{
		ulResult = ::SOF_InitializeLibraryNative("WTSKFInterface.dll", &ckpFunctions);
		if (SOR_OK != ulResult)
		{
			goto end;
		}
		this->SOF_GetDefaultContainer();
	}

	ulResult = ::SOF_GetCertInfo(ckpFunctions, (BYTE *)mix_b64_decode(strCert).c_str(), mix_b64_decode(strCert).size(), u16Type, data_info_value, &data_info_len);
	if (SOR_OK != ulResult)
	{
		goto end;
	}

	strResult = std::string(data_info_value, data_info_value + data_info_len);
end:

	return strResult;
}

std::string FBWTSofPluginAPI::SOF_GetCertInfoByOid(std::string strCert, std::string strOidString)
{
	std::string strResult;
	BYTE data_info_value[1024 * 4] = { 0 };
	ULONG data_info_len = sizeof(data_info_value);

	if (NULL == ckpFunctions)
	{
		ulResult = ::SOF_InitializeLibraryNative("WTSKFInterface.dll", &ckpFunctions);
		if (SOR_OK != ulResult)
		{
			goto end;
		}
		this->SOF_GetDefaultContainer();
	}

	ulResult = ::SOF_GetCertInfoByOid(ckpFunctions, (BYTE *)mix_b64_decode(strCert).c_str(), mix_b64_decode(strCert).size(), (LPSTR)strOidString.c_str(), data_info_value, &data_info_len);
	if (SOR_OK != ulResult)
	{
		goto end;
	}

	strResult = std::string(data_info_value, data_info_value + data_info_len);
end:

	return strResult;
}

std::string FBWTSofPluginAPI::SOF_GetDeviceInfo(std::string strContainerName, ULONG ulType)
{
	std::string strResult;
	BYTE data_info_value[1024 * 4] = { 0 };
	ULONG data_info_len = sizeof(data_info_value);

	if (NULL == ckpFunctions)
	{
		ulResult = ::SOF_InitializeLibraryNative("WTSKFInterface.dll", &ckpFunctions);
		if (SOR_OK != ulResult)
		{
			goto end;
		}
		this->SOF_GetDefaultContainer();
	}
	if ((strContainerName.size() == 0) || (strContainerName == "")) strContainerName = m_default_container;

	ulResult = ::SOF_GetDeviceInfo(ckpFunctions, (LPSTR)strContainerName.c_str(), ulType, data_info_value, &data_info_len);
	if (SOR_OK != ulResult)
	{
		goto end;
	}

	strResult = std::string(data_info_value, data_info_value + data_info_len);
end:

	return strResult;
}

ULONG FBWTSofPluginAPI::SOF_ValidateCert(std::string strCert)
{
	ULONG ulValidate = 0;

	if (NULL == ckpFunctions)
	{
		ulResult = ::SOF_InitializeLibraryNative("WTSKFInterface.dll", &ckpFunctions);
		if (SOR_OK != ulResult)
		{
			goto end;
		}
		this->SOF_GetDefaultContainer();
	}

	ulResult = ::SOF_ValidateCert(ckpFunctions, (BYTE *)mix_b64_decode(strCert).c_str(), mix_b64_decode(strCert).size(), &ulValidate);
	if (SOR_OK != ulResult)
	{
		goto end;
	}

end:

	return ulValidate;
}

std::string FBWTSofPluginAPI::SOF_SignData(std::string strContainerName, std::string strDataIn)
{
	std::string strResult;
	BYTE data_info_value[1024] = { 0 };
	ULONG data_info_len = 0;

	if (NULL == ckpFunctions)
	{
		ulResult = ::SOF_InitializeLibraryNative("WTSKFInterface.dll", &ckpFunctions);
		if (SOR_OK != ulResult)
		{
			goto end;
		}
		this->SOF_GetDefaultContainer();
	}
	if ((strContainerName.size() == 0) || (strContainerName == "")) strContainerName = m_default_container;

	// 	ulResult = ::SOF_SignData(ckpFunctions, (LPSTR)strContainerName.c_str(),  (BYTE*)mix_b64_decode(strDataIn).c_str(), mix_b64_decode(strDataIn).size(), data_info_value, &data_info_len);
	// 	if (SOR_OK != ulResult)
	// 	{
	// 		goto end;
	// 	}

	data_info_len = sizeof(data_info_value);
	memset(data_info_value, 0x00, data_info_len);
	ulResult = ::SOF_SignData(ckpFunctions, (LPSTR)strContainerName.c_str(), (BYTE*)mix_b64_decode(strDataIn).c_str(), mix_b64_decode(strDataIn).size(), data_info_value, &data_info_len);
	if (SOR_OK != ulResult)
	{
		goto end;
	}

	strResult = std::string(data_info_value, data_info_value + data_info_len);
	strResult = mix_b64_encode(strResult);

end:
	return strResult;
}

BOOL FBWTSofPluginAPI::SOF_VerifySignedData(std::string strCert, std::string strDataIn, std::string strDataOut)
{
	if (NULL == ckpFunctions)
	{
		ulResult = ::SOF_InitializeLibraryNative("WTSKFInterface.dll", &ckpFunctions);
		if (SOR_OK != ulResult)
		{
			goto end;
		}
		this->SOF_GetDefaultContainer();
	}


	ulResult = ::SOF_VerifySignedData(ckpFunctions, (BYTE *)mix_b64_decode(strCert).c_str(), mix_b64_decode(strCert).size(), (BYTE*)mix_b64_decode(strDataIn).c_str(), mix_b64_decode(strDataIn).size(), (BYTE *)mix_b64_decode(strDataOut).c_str(), mix_b64_decode(strDataOut).size());
	if (SOR_OK != ulResult)
	{
		goto end;
	}

end:
	return !ulResult;
}

std::string FBWTSofPluginAPI::SOF_SignFile(std::string strContainerName, std::string strFileIn)
{
	std::string strResult;
	BYTE data_info_value[1024];
	ULONG data_info_len = 0;

	if (NULL == ckpFunctions)
	{
		ulResult = ::SOF_InitializeLibraryNative("WTSKFInterface.dll", &ckpFunctions);
		if (SOR_OK != ulResult)
		{
			goto end;
		}
		this->SOF_GetDefaultContainer();
	}
	if ((strContainerName.size() == 0) || (strContainerName == "")) strContainerName = m_default_container;

	// 	ulResult = ::SOF_SignFile(ckpFunctions, (LPSTR)strContainerName.c_str(),  (LPSTR)strFileIn.c_str(), data_info_value, &data_info_len);
	// 	if (SOR_OK != ulResult)
	// 	{
	// 		goto end;
	// 	}

	data_info_len = sizeof(data_info_value);
	memset(data_info_value, 0x00, data_info_len);
	ulResult = ::SOF_SignFile(ckpFunctions, (LPSTR)strContainerName.c_str(), (LPSTR)strFileIn.c_str(), data_info_value, &data_info_len);
	if (SOR_OK != ulResult)
	{
		goto end;
	}

	strResult = std::string(data_info_value, data_info_value + data_info_len);
	strResult = mix_b64_encode(strResult);

end:
	return strResult;
}

BOOL FBWTSofPluginAPI::SOF_VerifySignedFile(std::string strCert, std::string strFileIn, std::string strDataOut)
{
	if (NULL == ckpFunctions)
	{
		ulResult = ::SOF_InitializeLibraryNative("WTSKFInterface.dll", &ckpFunctions);
		if (SOR_OK != ulResult)
		{
			goto end;
		}
		this->SOF_GetDefaultContainer();
	}

	ulResult = ::SOF_VerifySignedFile(ckpFunctions, (BYTE *)mix_b64_decode(strCert).c_str(), mix_b64_decode(strCert).size(), (LPSTR)strFileIn.c_str(), (BYTE *)mix_b64_decode(strDataOut).c_str(), mix_b64_decode(strDataOut).size());
	if (SOR_OK != ulResult)
	{
		goto end;
	}

end:
	return !ulResult;
}

std::string FBWTSofPluginAPI::SOF_EncryptData(std::string strCert, std::string strDataIn)
{
	std::string strResult;
	BYTE *data_info_value = NULL;
	ULONG data_info_len = 0;

	if (NULL == ckpFunctions)
	{
		ulResult = ::SOF_InitializeLibraryNative("WTSKFInterface.dll", &ckpFunctions);
		if (SOR_OK != ulResult)
		{
			goto end;
		}
		this->SOF_GetDefaultContainer();
	}

	ulResult = ::SOF_EncryptData(ckpFunctions, (BYTE *)mix_b64_decode(strCert).c_str(), mix_b64_decode(strCert).size(), (BYTE*)strDataIn.c_str(), strDataIn.size(), data_info_value, &data_info_len);
	if (SOR_OK != ulResult)
	{
		goto end;
	}
	data_info_len += 128;

	data_info_value = new BYTE[data_info_len];
	ulResult = ::SOF_EncryptData(ckpFunctions, (BYTE *)mix_b64_decode(strCert).c_str(), mix_b64_decode(strCert).size(), (BYTE*)strDataIn.c_str(), strDataIn.size(), data_info_value, &data_info_len);
	if (SOR_OK != ulResult)
	{
		goto end;
	}

	strResult = std::string(data_info_value, data_info_value + data_info_len);
	strResult = mix_b64_encode(strResult);

end:
	if (data_info_value)
	{
		delete[] data_info_value;
	}

	return strResult;
}

std::string FBWTSofPluginAPI::SOF_DecryptData(std::string strContainerName, std::string strDataIn)
{
	std::string strResult;
	BYTE *data_info_value = NULL;
	ULONG data_info_len = 0;

	if (NULL == ckpFunctions)
	{
		ulResult = ::SOF_InitializeLibraryNative("WTSKFInterface.dll", &ckpFunctions);
		if (SOR_OK != ulResult)
		{
			goto end;
		}
		this->SOF_GetDefaultContainer();
	}
	if ((strContainerName.size() == 0) || (strContainerName == "")) strContainerName = m_default_container;


	data_info_len = strDataIn.size() + 1024;
	data_info_value = new BYTE[data_info_len];
	ulResult = ::SOF_DecryptData(ckpFunctions, (LPSTR)strContainerName.c_str(), (BYTE *)mix_b64_decode(strDataIn).c_str(), mix_b64_decode(strDataIn).size(), data_info_value, &data_info_len);
	if (SOR_OK != ulResult)
	{
		goto end;
	}

	strResult = std::string(data_info_value, data_info_value + data_info_len);
	//strResult = mix_b64_encode(strResult);
end:

	if (data_info_value)
	{
		delete[] data_info_value;
	}

	return strResult;
}

BOOL FBWTSofPluginAPI::SOF_EncryptFile(std::string strCert, std::string strFileIn, std::string strFileOut)
{
	if (NULL == ckpFunctions)
	{
		ulResult = ::SOF_InitializeLibraryNative("WTSKFInterface.dll", &ckpFunctions);
		if (SOR_OK != ulResult)
		{
			goto end;
		}
		this->SOF_GetDefaultContainer();
	}


	ulResult = ::SOF_EncryptFile(ckpFunctions, (BYTE *)mix_b64_decode(strCert).c_str(), mix_b64_decode(strCert).size(), (LPSTR)strFileIn.c_str(), (LPSTR)strFileOut.c_str());
	if (SOR_OK != ulResult)
	{
		goto end;
	}
end:

	return !ulResult;
}

BOOL FBWTSofPluginAPI::SOF_DecryptFile(std::string strContainerName, std::string strFileIn, std::string strFileOut)
{
	if (NULL == ckpFunctions)
	{
		ulResult = ::SOF_InitializeLibraryNative("WTSKFInterface.dll", &ckpFunctions);
		if (SOR_OK != ulResult)
		{
			goto end;
		}
		this->SOF_GetDefaultContainer();
	}
	if ((strContainerName.size() == 0) || (strContainerName == "")) strContainerName = m_default_container;

	ulResult = ::SOF_DecryptFile(ckpFunctions, (LPSTR)strContainerName.c_str(), (LPSTR)strFileIn.c_str(), (LPSTR)strFileOut.c_str());
	if (SOR_OK != ulResult)
	{
		goto end;
	}
end:

	return !ulResult;
}

std::string FBWTSofPluginAPI::SOF_SignMessage(UINT16 u16Flag, std::string strContainerName, std::string strDataIn)
{
	std::string strResult;
	BYTE *data_info_value = NULL;
	ULONG data_info_len = 0;

	if (NULL == ckpFunctions)
	{
		ulResult = ::SOF_InitializeLibraryNative("WTSKFInterface.dll", &ckpFunctions);
		if (SOR_OK != ulResult)
		{
			goto end;
		}
		this->SOF_GetDefaultContainer();
	}
	if ((strContainerName.size() == 0) || (strContainerName == "")) strContainerName = m_default_container;

	// 	ulResult = ::SOF_SignMessage(ckpFunctions, (LPSTR)strContainerName.c_str(), u16Flag, (BYTE*)strDataIn.c_str(), strDataIn.size(), data_info_value, &data_info_len);
	// 	if (SOR_OK != ulResult)
	// 	{
	// 		goto end;
	// 	}
	// 	data_info_len += 128;

	data_info_len = strDataIn.size() + 4096;
	data_info_value = new BYTE[data_info_len];
	ulResult = ::SOF_SignMessage(ckpFunctions, (LPSTR)strContainerName.c_str(), u16Flag, (BYTE *)mix_b64_decode(strDataIn).c_str(), mix_b64_decode(strDataIn).size(), data_info_value, &data_info_len);
	if (SOR_OK != ulResult)
	{
		goto end;
	}

	strResult = std::string(data_info_value, data_info_value + data_info_len);
	strResult = mix_b64_encode(strResult);

end:

	if (data_info_value)
	{
		delete[] data_info_value;
		data_info_value = NULL;
	}

	return strResult;
}

BOOL FBWTSofPluginAPI::SOF_VerifySignedMessage(std::string strMessageData, std::string strPlaintext)
{
	if (NULL == ckpFunctions)
	{
		ulResult = ::SOF_InitializeLibraryNative("WTSKFInterface.dll", &ckpFunctions);
		if (SOR_OK != ulResult)
		{
			goto end;
		}
		this->SOF_GetDefaultContainer();
	}

	ulResult = ::SOF_VerifySignedMessage(ckpFunctions, (BYTE *)mix_b64_decode(strMessageData).c_str(), mix_b64_decode(strMessageData).size(), (BYTE *)mix_b64_decode(strPlaintext).c_str(), mix_b64_decode(strPlaintext).size());
	if (SOR_OK != ulResult)
	{
		goto end;
	}

end:

	return !ulResult;
}

std::string FBWTSofPluginAPI::SOF_GetInfoFromSignedMessage(std::string strMessageData, UINT16 u16Type)
{
	std::string strResult;
	BYTE *data_info_value = NULL;
	ULONG data_info_len = 0;

	if (NULL == ckpFunctions)
	{
		ulResult = ::SOF_InitializeLibraryNative("WTSKFInterface.dll", &ckpFunctions);
		if (SOR_OK != ulResult)
		{
			goto end;
		}
		this->SOF_GetDefaultContainer();
	}

	data_info_len = strMessageData.size();
	data_info_value = new BYTE[data_info_len];
	ulResult = ::SOF_GetInfoFromSignedMessage(ckpFunctions, u16Type, (BYTE *)mix_b64_decode(strMessageData).c_str(), mix_b64_decode(strMessageData).size(), data_info_value, &data_info_len);
	if (SOR_OK != ulResult)
	{
		goto end;
	}

	strResult = std::string(data_info_value, data_info_value + data_info_len);
	strResult = mix_b64_encode(strResult);

end:

	if (data_info_value)
	{
		delete[] data_info_value;
	}

	return strResult;
}

std::string FBWTSofPluginAPI::SOF_SignDataXML(std::string strContainerName, std::string strDataIn)
{
	std::string strResult;
	BYTE *data_info_value = NULL;
	ULONG data_info_len = 0;

	if (NULL == ckpFunctions)
	{
		ulResult = ::SOF_InitializeLibraryNative("WTSKFInterface.dll", &ckpFunctions);
		if (SOR_OK != ulResult)
		{
			goto end;
		}
		this->SOF_GetDefaultContainer();
	}
	if ((strContainerName.size() == 0) || (strContainerName == "")) strContainerName = m_default_container;

	ulResult = ::SOF_SignDataXML(ckpFunctions, (LPSTR)strContainerName.c_str(), (BYTE*)strDataIn.c_str(), strDataIn.size(), data_info_value, &data_info_len);
	if (SOR_OK != ulResult)
	{
		goto end;
	}
	data_info_len += 128;

	data_info_value = new BYTE[data_info_len];
	memset(data_info_value, 0x00, data_info_len);
	ulResult = ::SOF_SignDataXML(ckpFunctions, (LPSTR)strContainerName.c_str(), (BYTE*)strDataIn.c_str(), strDataIn.size(), data_info_value, &data_info_len);
	if (SOR_OK != ulResult)
	{
		goto end;
	}

	strResult = std::string(data_info_value, data_info_value + data_info_len);
end:

	if (data_info_value)
	{
		delete[] data_info_value;
		data_info_value = NULL;
	}

	return strResult;
}

BOOL FBWTSofPluginAPI::SOF_VerifySignedDataXML(std::string strDataIn)
{
	if (NULL == ckpFunctions)
	{
		ulResult = ::SOF_InitializeLibraryNative("WTSKFInterface.dll", &ckpFunctions);
		if (SOR_OK != ulResult)
		{
			goto end;
		}
		this->SOF_GetDefaultContainer();
	}

	ulResult = ::SOF_VerifySignedDataXML(ckpFunctions, (BYTE*)strDataIn.c_str(), strDataIn.size());
	if (SOR_OK != ulResult)
	{
		goto end;
	}

end:

	return !ulResult;
}

std::string FBWTSofPluginAPI::SOF_GetXMLSignatureInfo(std::string strDataIn, UINT16 u16Type)
{
	std::string strResult;
	BYTE *data_info_value = NULL;
	ULONG data_info_len = 0;

	if (NULL == ckpFunctions)
	{
		ulResult = ::SOF_InitializeLibraryNative("WTSKFInterface.dll", &ckpFunctions);
		if (SOR_OK != ulResult)
		{
			goto end;
		}
		this->SOF_GetDefaultContainer();
	}

	data_info_len = strDataIn.size();
	data_info_value = new BYTE[data_info_len];
	ulResult = ::SOF_GetXMLSignatureInfo(ckpFunctions, u16Type, (BYTE*)strDataIn.c_str(), strDataIn.size(), data_info_value, &data_info_len);
	if (SOR_OK != ulResult)
	{
		goto end;
	}

	strResult = std::string(data_info_value, data_info_value + data_info_len);
end:
	if (data_info_value)
	{
		delete[] data_info_value;
	}

	return strResult;
}

std::string FBWTSofPluginAPI::SOF_GenRandom(UINT16 u16Type)
{
	std::string strResult;
	BYTE *data_info_value = NULL;

	if (NULL == ckpFunctions)
	{
		ulResult = ::SOF_InitializeLibraryNative("WTSKFInterface.dll", &ckpFunctions);
		if (SOR_OK != ulResult)
		{
			goto end;
		}
		this->SOF_GetDefaultContainer();
	}

	data_info_value = new BYTE[u16Type];
	ulResult = ::SOF_GenRandom(ckpFunctions, (BYTE *)data_info_value, (ULONG)u16Type);
	if (SOR_OK != ulResult)
	{
		goto end;
	}

	strResult = std::string(data_info_value, data_info_value + u16Type);
	strResult = mix_b64_encode(strResult);

end:

	if (data_info_value)
	{
		delete[] data_info_value;
	}

	return strResult;
}

ULONG FBWTSofPluginAPI::SOF_GetLastError()
{
	return ulResult;
}


std::string FBWTSofPluginAPI::SOF_PubKeyEncrypt(std::string strCert, std::string strDataIn)
{
	std::string strResult;
	BYTE *data_info_value = NULL;
	ULONG data_info_len = 0;

	if (NULL == ckpFunctions)
	{
		ulResult = ::SOF_InitializeLibraryNative("WTSKFInterface.dll", &ckpFunctions);
		if (SOR_OK != ulResult)
		{
			goto end;
		}
		this->SOF_GetDefaultContainer();
	}

	ulResult = ::SOF_PubKeyEncrypt(ckpFunctions, (BYTE*)mix_b64_decode(strCert).c_str(), mix_b64_decode(strCert).size(), (BYTE*)mix_b64_decode(strDataIn).c_str(), mix_b64_decode(strDataIn).size(), data_info_value, &data_info_len);
	if (SOR_OK != ulResult)
	{
		goto end;
	}
	data_info_len += 128;

	data_info_value = new BYTE[data_info_len];
	ulResult = ::SOF_PubKeyEncrypt(ckpFunctions, (BYTE*)mix_b64_decode(strCert).c_str(), mix_b64_decode(strCert).size(), (BYTE*)mix_b64_decode(strDataIn).c_str(), mix_b64_decode(strDataIn).size(), data_info_value, &data_info_len);
	if (SOR_OK != ulResult)
	{
		goto end;
	}

	strResult = std::string(data_info_value, data_info_value + data_info_len);
	strResult = mix_b64_encode(strResult);

end:
	if (data_info_value)
	{
		delete[] data_info_value;
	}

	return strResult;
}

std::string FBWTSofPluginAPI::SOF_PriKeyDecrypt(std::string strContainerName, std::string strDataIn)
{
	std::string strResult;
	BYTE *data_info_value = NULL;
	ULONG data_info_len = 0;

	if (NULL == ckpFunctions)
	{
		ulResult = ::SOF_InitializeLibraryNative("WTSKFInterface.dll", &ckpFunctions);
		if (SOR_OK != ulResult)
		{
			goto end;
		}
		this->SOF_GetDefaultContainer();
	}
	if ((strContainerName.size() == 0) || (strContainerName == "")) strContainerName = m_default_container;

	ulResult = ::SOF_PriKeyDecrypt(ckpFunctions, (LPSTR)strContainerName.c_str(), (BYTE *)mix_b64_decode(strDataIn).c_str(), mix_b64_decode(strDataIn).size(), data_info_value, &data_info_len);
	if (SOR_OK != ulResult)
	{
		goto end;
	}
	data_info_len += 128;

	data_info_value = new BYTE[data_info_len];
	ulResult = ::SOF_PriKeyDecrypt(ckpFunctions, (LPSTR)strContainerName.c_str(), (BYTE *)mix_b64_decode(strDataIn).c_str(), mix_b64_decode(strDataIn).size(), data_info_value, &data_info_len);
	if (SOR_OK != ulResult)
	{
		goto end;
	}

	strResult = std::string(data_info_value, data_info_value + data_info_len);
	strResult = mix_b64_encode(strResult);
end:

	if (data_info_value)
	{
		delete[] data_info_value;
	}

	return strResult;
}

std::string FBWTSofPluginAPI::SOF_PubKeyEncryptLongData(std::string strCert, std::string strDataIn)
{
	return this->SOF_PubKeyEncrypt(strCert, strDataIn);
}

std::string FBWTSofPluginAPI::SOF_PriKeyDecryptLongData(std::string strContainerName, std::string strDataIn)
{
	return this->SOF_PriKeyDecrypt(strContainerName, strDataIn);
}


void FBWTSofPluginAPI::SOF_GetDefaultContainer()
{
	BYTE data_info_value_userlist[1024] = { 0 };
	ULONG data_info_len_userlist = sizeof(data_info_value_userlist);

	std::string tmp;

	ulResult = ::SOF_GetUserList(ckpFunctions, data_info_value_userlist, &data_info_len_userlist);
	if (SOR_OK != ulResult)
	{
		goto end;
	}

	if (NULL == strstr((char*)data_info_value_userlist, "||"))
	{
		m_default_container = std::string();
	}
	else
	{
		if (NULL == strstr((char*)data_info_value_userlist, "&&&"))
		{
			m_default_container = std::string(strstr((char*)data_info_value_userlist, "||") + 2);
		}
		else
		{
			m_default_container = std::string(strstr((char*)data_info_value_userlist, "||") + 2, strstr((char*)data_info_value_userlist, "&&&"));
		}
	}
end:
	return;
}


BOOL FBWTSofPluginAPI::SOF_Logout()
{
	ulResult = ::SOF_Logout(ckpFunctions);
	ckpFunctions = NULL;

	return !ulResult;
}


BOOL FBWTSofPluginAPI::SOF_InitializeLibraryNative(std::string strLibrary)
{
	if (NULL != ckpFunctions)
	{
		ulResult = ::SOF_FinalizeLibraryNative(&ckpFunctions);
		ckpFunctions = NULL;
	}

	if (NULL == ckpFunctions)
	{
		ulResult = ::SOF_InitializeLibraryNative((char *)strLibrary.c_str(), &ckpFunctions);
		if (SOR_OK != ulResult)
		{
			goto end;
		}
		this->SOF_GetDefaultContainer();
	}
end:
	return !ulResult;
}



BOOL FBWTSofPluginAPI::SOF_FinalizeLibraryNative()
{
	if (NULL != ckpFunctions)
	{
		ulResult = ::SOF_FinalizeLibraryNative(&ckpFunctions);
		ckpFunctions = NULL;
	}

	return !ulResult;
}


#define REG_ROOT_KEY HKEY_LOCAL_MACHINE
#define REG_SUB_KEY_PREFIX "SOFTWARE\\Microsoft\\Cryptography\\Defaults\\SKF"
#define REG_VALUE_PATH_KEYNAME "path"
#define EErr_SMC_MEM_LES 0xFF

unsigned int __stdcall WTF_EnumSKF(char * pszSKFNames, unsigned int * puiSKFNamesLen)
{
	unsigned int ulRet = -1;
	HKEY hKey;
	DWORD dwIndex = 0, NameSize, NameCnt, NameMaxLen;
	char data_value[BUFFER_LEN_1K] = { 0 };
	LPCSTR SubKey = REG_SUB_KEY_PREFIX;
	char * szValueName;
	unsigned int len_out = 0;

	if (RegOpenKeyExA(REG_ROOT_KEY, SubKey, 0, KEY_READ, &hKey) !=
		ERROR_SUCCESS)
	{
		DEBUG("RegOpenKeyEx错误");
		return -1;
	}
	//获取子键信息---------------------------------------------------------------
	if (RegQueryInfoKeyA(hKey, NULL, NULL, NULL, &NameCnt, &NameMaxLen, NULL, NULL, NULL, NULL, NULL, NULL) != ERROR_SUCCESS)
	{
		DEBUG("RegQueryInfoKey错误");
		RegCloseKey(hKey);
		return -1;
	}

	//枚举键值信息--------------------------------------------------------------
	for (dwIndex = 0; dwIndex<NameCnt; dwIndex++)    //枚举键
	{
		NameSize = NameMaxLen + 1;
		szValueName = (char *)malloc(NameSize);

		memset(szValueName, 0, NameSize);

		RegEnumKeyExA(hKey, dwIndex, szValueName, &NameSize, NULL, NULL, NULL, NULL);//读取键

		DEBUG("%s %s\n", szValueName, "");

		memcpy(data_value + len_out, szValueName, NameSize);

		len_out += NameSize + 1;

		free(szValueName);

		szValueName = 0;
	}

	if (len_out)
	{
		len_out += 1;
	}

	if (NULL == pszSKFNames)
	{
		*puiSKFNamesLen = len_out;
		ulRet = 0;
	}
	else if (*puiSKFNamesLen < len_out)
	{
		*puiSKFNamesLen = len_out;
		ulRet = EErr_SMC_MEM_LES;
	}
	else
	{
		*puiSKFNamesLen = len_out;
		memcpy(pszSKFNames, data_value, len_out);
		ulRet = 0;
	}

	RegCloseKey(hKey);

	return ulRet;
}

unsigned int __stdcall WTF_ReadSKFPath(const char * pszSKFName, char * pszDllPath, unsigned int *puiDllPathLen)
{
	unsigned int ulRet = -1;
	HKEY hKey;
	DWORD DataSize, MaxDateLen;
	DWORD dwIndex = 0, NameSize, NameCnt, NameMaxLen, Type;
	char SubKey[BUFFER_LEN_1K] = { 0 };

	//LPCSTR SubKey[] =  REG_SUB_KEY_PREFIX;

	char * szValueName;
	LPBYTE  szValueData;

	strcat(SubKey, REG_SUB_KEY_PREFIX);
	strcat(SubKey, "\\");
	strcat(SubKey, pszSKFName);

	if (RegOpenKeyExA(REG_ROOT_KEY, SubKey, 0, KEY_READ, &hKey) !=
		ERROR_SUCCESS)
	{
		DEBUG("RegOpenKeyEx错误");
		return -1;
	}

	//获取子键信息---------------------------------------------------------------
	if (RegQueryInfoKey(hKey, NULL, NULL, NULL, NULL, NULL, NULL, &NameCnt, &NameMaxLen, &MaxDateLen, NULL, NULL) != ERROR_SUCCESS)
	{
		DEBUG("RegQueryInfoKey错误");
		RegCloseKey(hKey);
		return -1;
	}
	//枚举键值信息--------------------------------------------------------------
	for (dwIndex = 0; dwIndex<NameCnt; dwIndex++)    //枚举键
	{
		DataSize = MaxDateLen + 1;
		NameSize = NameMaxLen + 1;
		szValueName = (char *)malloc(NameSize);
		szValueData = (LPBYTE)malloc(DataSize);

		memset(szValueName, 0, NameSize);
		memset(szValueData, 0, DataSize);

		RegEnumValueA(hKey, dwIndex, szValueName, &NameSize, NULL, &Type, szValueData, &DataSize);//读取键

		DEBUG("%s %s\n", szValueName, szValueData);

		if (0 == (strcmp(szValueName, REG_VALUE_PATH_KEYNAME)))
		{
			if (NULL == pszDllPath)
			{
				*puiDllPathLen = DataSize;
				ulRet = 0;
			}
			else if (*puiDllPathLen < DataSize)
			{
				*puiDllPathLen = DataSize;
				ulRet = EErr_SMC_MEM_LES;
			}
			else
			{
				*puiDllPathLen = DataSize;
				memcpy(pszDllPath, szValueData, DataSize);
				ulRet = 0;
			}

			break;
		}

		free(szValueName);
		free(szValueData);
		szValueName = 0;
		szValueData = 0;
	}

	RegCloseKey(hKey);


	return ulRet;
}

#include <json/json.h>

std::string FBWTSofPluginAPI::SOF_GetSupportSKFList()
{
	char * szSKFAll = new char[BUFFER_LEN_1K];
	unsigned int ulSKFAll = BUFFER_LEN_1K;
	char * ptr_SKF = NULL;

	unsigned int dllPathLen = BUFFER_LEN_1K;
	char *  dllPathValue = new char[BUFFER_LEN_1K];

	Json::Value items = Json::Value(Json::arrayValue);

	WTF_EnumSKF(szSKFAll, &ulSKFAll);



	int i = 0;


	for (ptr_SKF = szSKFAll; (ptr_SKF < szSKFAll + ulSKFAll) && *ptr_SKF != 0;)
	{
		Json::Value item;

		dllPathLen = BUFFER_LEN_1K;
		memset(dllPathValue, 0, dllPathLen);

		WTF_ReadSKFPath(ptr_SKF, dllPathValue, &dllPathLen);

		item["name"] = ptr_SKF;
		item["path"] = dllPathValue;

		items[i] = item;

		i++;
		// next SKF
		ptr_SKF += strlen(ptr_SKF) + 1;
	}

end:

	if (dllPathValue)
	{
		delete[] dllPathValue;
		dllPathValue = NULL;
	}

	if (szSKFAll)
	{
		delete[] szSKFAll;
		szSKFAll = NULL;
	}

	return items.toStyledString();
}