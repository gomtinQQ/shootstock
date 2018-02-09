
// shootStockDlg.h : 헤더 파일
//

#pragma once

#include "afxcmn.h"

#include "BuyList.h"
#include "CurPrice.h"
#include "TopPrice.h"
#include "JongDlg.h"
#include "DailyReport.h"
#include "ChartView.h"

#define WM_UPDATESTATUSBAR WM_USER + 255

// CshootStockDlg 대화 상자
class CshootStockDlg : public CDialogEx
{
// 생성입니다.
public:
	CshootStockDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_SHOOTSTOCK_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.
public:
	CMapStringToPtr m_mapScreen;
	CMapStringToString m_OrderList;
	CString							m_strScrNo;
	CMapStringToString		m_mapJongCode;		// 리얼등록 종목
	CMapStringToString		m_mapOrderNo;
	int m_nScrN0;
	CMapStringToString m_mapScreenNum;
	long								m_nCount;					// 그리드 Row 갯수.
	BOOL							m_bNextFlag;				// 연속조회 유무 플래그.

	CString							m_AccNo;

	double							m_BuyComm;			// 매수가계산 수수료(계산)
	double							m_SellComm;			// 매도가계산 수수료(계산)
	double							m_Tax;						// 제세금(계산)
	double							m_Eval;						// 평가금액(현금, 신용/대출)
	double							m_Profit;					// 평가손익(현금, 신용/대출)
	double							m_Rate;						// 수익률


	BOOL GetNextScreenNum(int nScreenType);
	long		m_nRet;
// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	void MainOnReceiveTrDataKhopenapictrl(LPCTSTR sScrNo, LPCTSTR sRQName, LPCTSTR sTrcode, LPCTSTR sRecordName, LPCTSTR sPrevNext, long nDataLength, LPCTSTR sErrorCode, LPCTSTR sMessage, LPCTSTR sSplmMsg);
	void OnReceiveTrDataKhopenapictrl(LPCTSTR sScrNo, LPCTSTR sRQName, LPCTSTR sTrcode, LPCTSTR sRecordName, LPCTSTR sPrevNext, long nDataLength, LPCTSTR sErrorCode, LPCTSTR sMessage, LPCTSTR sSplmMsg);
	void MainOnReceiveRealDataKhopenapictrl(LPCTSTR sJongmokCode, LPCTSTR sRealType, LPCTSTR sRealData);
	void OnReceiveRealDataKhopenapictrl(LPCTSTR sJongmokCode, LPCTSTR sRealType, LPCTSTR sRealData);
	void OnReceiveMsgKhopenapictrl(LPCTSTR sScrNo, LPCTSTR sRQName, LPCTSTR sTrCode, LPCTSTR sMsg);
	void MainOnReceiveChejanData(LPCTSTR sGubun, LONG nItemCnt, LPCTSTR sFidList);
	void OnReceiveChejanData(LPCTSTR sGubun, LONG nItemCnt, LPCTSTR sFidList);
	void OnEventConnect(LONG nItemCnt);
	void OnReceiveRealCondition(LPCTSTR strCode, LPCTSTR strType, LPCTSTR strConditionName, LPCTSTR strConditionIndex);			//조건검색 실시간 삽입,삭제되는 종목을 받는다
	void OnReceiveTrCondition(LPCTSTR sScrNo, LPCTSTR strCodeList, LPCTSTR strConditionName, int nIndex, int nNext);	//조건검색 종목리스트를 받는다.
	void OnReceiveConditionVer(long lRet, LPCTSTR sMsg);
	DECLARE_EVENTSINK_MAP()
public:
	
protected:
	afx_msg LRESULT OnUpdatestatusbar(WPARAM wParam, LPARAM lParam);
public:
	CBuyList m_buyList;
	CCurPrice m_curPrice;
	CTopPrice m_topPrice;
	CJongDlg  m_JongDlg;
	CDailyReport m_DailyReport;
	CChartView m_ChartView;
	CStatusBar m_StatusBar;
	void InitStatusBar(void);
	void OnBtnGetAccData(void);
	CListCtrl m_logList;
	void InitlogList(void);
	void TraceOutputA(const char* fmt,...);
	void TraceOutputW(const TCHAR* fmt,...);
	CTabCtrl m_TabControl;
	void InitTabControl(void);
	afx_msg void OnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult);
	CReportCtrl m_dealList;
	void InitDealList(void);
	void SetRate(int nRow, CString strCode);
	void SetTotalRate();

	afx_msg void OnListSearch();
	CString m_staticCode;
	CString m_staticName;
	CString m_staticPrice;
	CString m_boardJongmokCode;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	float m_sellPercentage;
	int m_FuckPercentage;
	bool isRunning;
	// 매수 체결가
	int m_boughtPrice;
	// 체결된 수량
	int m_checkedCount;
	CString m_checkedCode;
	int m_boughtCount;
};
