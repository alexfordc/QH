// QH.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "QH.h"
#include "QHDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CQHApp

BEGIN_MESSAGE_MAP(CQHApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CQHApp ����

CQHApp::CQHApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
	for(int i=0;i<100;i++)
	{
		memset(mDepthMarketDataField[i].InstrumentID,0,sizeof(TThostFtdcInstrumentIDType));
	}
}


// Ψһ��һ�� CQHApp ����

CQHApp theApp;


// CQHApp ��ʼ��

BOOL CQHApp::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	AfxEnableControlContainer();

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	CQHDlg dlg;
	m_pMainWnd = &dlg;
	mdlg = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}

	
	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}

void CQHApp::Message(CString  str)
{
	mdlg->Message(str);
}
void CQHApp::OnRspQryInvestorPosition(CThostFtdcInvestorPositionField *pInvestorPosition)
{
	mdlg->UpdateChiChangList(pInvestorPosition);
}
void CQHApp::OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData)
{
	TThostFtdcInstrumentIDType nullId;
	memset(nullId,0,sizeof(TThostFtdcInstrumentIDType));
	int i=0;
	for(i=0;i<100;i++)
	{
		if(0==strcmp(pDepthMarketData->InstrumentID ,mDepthMarketDataField[i].InstrumentID) || 
			0==strcmp(nullId ,mDepthMarketDataField[i].InstrumentID))
		{
			mDepthMarketDataField[i] = *pDepthMarketData;
			break;
		}
	}
	mdlg->UpdateHangQinList(i);

}

void CQHApp::RtnOrder(CThostFtdcOrderField *pOrder)
{
	mdlg->RtnOrder(pOrder);
}