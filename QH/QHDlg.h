// QHDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CQHDlg �Ի���
class CQHDlg : public CDialog
{
// ����
public:
	CQHDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_QH_DIALOG };

	void Message(CString  str);
	void UpdateHangQinList(int i);
	void UpdateChiChangList(CThostFtdcInvestorPositionField *pInvestorPosition);
	void ClearChiChangItem();
	void EnableTrader(bool b){mCButtonIsAutoGo.EnableWindow(b);mCButtonTraderCancel.EnableWindow(b);mCButtonTraderGo.EnableWindow(b);mCButtonGo1.EnableWindow(b);mCButtonGo3.EnableWindow(b);	mCButtonClock.EnableWindow(b);};
	void EnableHangQin(){mCButtonAddHeYue.EnableWindow(true);};
	void SetMoney(char* str);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��
	
	
// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	void OnOK(){};
public:
	double mResult;
	bool result();
	void SetEnGUI(bool b);
	CListCtrl mCListCtrlHangQin;
	CListCtrl mCListCtrlChiChang;
	CListCtrl mCListCtrlTraderRecord;
	afx_msg void OnBnClickedButtonAdd();
	void CbnSelchangeCombo1Mm();
	void CbnSelchangeCombo2Mm();
	void CbnSelchangeCombo1TraderMm();
	void CbnSelchangeCombo2TraderMm();
	void calculate();
	CEdit mCEditAddQH;
	CComboBox mCComboBoxYunSuan;
	CComboBox mCComboBoxTiaoJian;
	CComboBox mCComboBoxQH1;
	CComboBox mCComboBoxQH2;
	CEdit mCEditTiaoJianValue;
	CStatic mCStaticQH1V;
	CStatic mCStaticQH2V;
	afx_msg void OnCbnSelchangeComboQh1();
	afx_msg void OnCbnSelchangeComboQh2();
	CComboBox mCComboBox1MM;
	CComboBox mCComboBox2MM;
	afx_msg void OnCbnSelendokComboQh1();
	afx_msg void OnCbnSelchangeCombo1Mm();
	afx_msg void OnCbnSelchangeCombo2Mm();
	afx_msg void OnCbnSelchangeComboYunsuan();
	afx_msg void OnCbnSelchangeComboTiaojian();
	CStatic mCStaticRE;
	CStatic mCStaticFlag;
	bool autodoit;
	CComboBox mCComboBoxMM1trader;
	CComboBox mCComboBoxMM2trader;
	CComboBox mCComboBoxKP1;
	CComboBox mCComboBoxKP2;
	CComboBox mCComboBoxNum1;
	CComboBox mCComboBoxNum2;
	afx_msg void OnBnClickedButtonGo();
	CComboBox mCComboBoxTraderQH1;
	CComboBox mCComboBoxTraderQH2;
	CStatic mCStaticTraderJiaGe1;
	CStatic mCStaticTraderJiaGe2;
	void GoTrader();
	void GoTrader1();
	void GoTrader2();
	void RtnOrder(CThostFtdcOrderField *pOrder);
	afx_msg void OnBnClickedButtonCancel();
	CButton mCButtonIsAutoGo;
	afx_msg void OnBnClickedCheckAuto();
	afx_msg void OnEnSetfocusEditTiaojianValue();
	afx_msg void OnCbnSetfocusComboQh1();
	CButton mCButtonTraderGo;
	CButton mCButtonTraderCancel;
	CButton mCButtonAddHeYue;
	CStatic mCStaticMoney;
	CButton mCButtonUpdate;
	CListCtrl mCListCtrlCJ;
	afx_msg void OnBnClickedButtonUpdate();
	void RtnTrader(CThostFtdcTradeField *pTrade);
	CButton mCButtonGo1;
	CButton mCButtonGo3;
	afx_msg void OnBnClickedButtonGo1();
	afx_msg void OnBnClickedButtonGo3();
	CButton mCButtonClock;
	afx_msg void OnBnClickedCheckClock();
};
