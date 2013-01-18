// FileTimeNewDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "FileTimeNew.h"
#include "FileTimeNewDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CFileTimeNewDlg �Ի���




CFileTimeNewDlg::CFileTimeNewDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFileTimeNewDlg::IDD, pParent)
	, m_FileName(_T(""))
	, m_strPath(_T(""))
	, m_strVisit(_T(""))
	, m_strWrite(_T(""))
	, m_strCreate(_T(""))
	, m_wTime(0)
	, m_cTime(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFileTimeNewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_EDIT2, m_visit);
	//DDX_Control(pDX, IDC_EDIT3, m_write);
	//DDX_Control(pDX, IDC_EDIT4, m_creation);
	DDX_Control(pDX, IDC_EDIT1, m_path);
	DDX_Control(pDX, IDC_EDIT2, m_visit);
	DDX_Control(pDX, IDC_EDIT3, m_write);
	DDX_Control(pDX, IDC_EDIT4, m_create);
}

BEGIN_MESSAGE_MAP(CFileTimeNewDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &CFileTimeNewDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CFileTimeNewDlg::OnBnClickedCancel)
	ON_WM_CLOSE()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_OPEN, &CFileTimeNewDlg::OnBnClickedOpen)
	ON_BN_CLICKED(IDC_SAVE, &CFileTimeNewDlg::OnBnClickedSave)
	ON_BN_CLICKED(IDC_README, &CFileTimeNewDlg::OnBnClickedReadme)
END_MESSAGE_MAP()


// CFileTimeNewDlg ��Ϣ�������

BOOL CFileTimeNewDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CFileTimeNewDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CFileTimeNewDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ��������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù����ʾ��
//
HCURSOR CFileTimeNewDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CFileTimeNewDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//OnOK();
}

void CFileTimeNewDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//OnCancel();
}

void CFileTimeNewDlg::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	DestroyWindow();
	CDialog::OnClose();
}

void CFileTimeNewDlg::OnDestroy()
{
	CDialog::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
	PostQuitMessage(0);
}

void CFileTimeNewDlg::OnBnClickedOpen()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CFileDialog   filedlg(true,NULL,NULL,OFN_DONTADDTORECENT,NULL,
		this,NULL);
	if(IDOK==filedlg.DoModal())
	{
		m_FileName=filedlg.GetPathName();
		m_path.SetWindowTextW(m_FileName);
		CFile File(m_FileName,CFile::modeReadWrite);
		CFileStatus FileStruct;
		File.GetStatus(FileStruct);

		//��ʾ����ʱ��
		m_strCreate.Format(_T("%u-%u-%u %u:%u:%u"),
			FileStruct.m_ctime.GetYear(),
			FileStruct.m_ctime.GetMonth(),
			FileStruct.m_ctime.GetDay(),
			FileStruct.m_ctime.GetHour(),
			FileStruct.m_ctime.GetMinute(),
			FileStruct.m_ctime.GetSecond());
		m_create.SetWindowTextW(m_strCreate);

		//��ʾ�޸�ʱ��
		m_strWrite.Format(_T("%u-%u-%u %u:%u:%u"),
			FileStruct.m_mtime.GetYear(),
			FileStruct.m_mtime.GetMonth(),
			FileStruct.m_mtime.GetDay(),
			FileStruct.m_mtime.GetHour(),
			FileStruct.m_mtime.GetMinute(),
			FileStruct.m_mtime.GetSecond());
		m_write.SetWindowTextW(m_strWrite);

		//��ʾ����ʱ��
		m_strVisit.Format(_T("%u-%u-%u %u:%u:%u"),
			FileStruct.m_atime.GetYear(),
			FileStruct.m_atime.GetMonth(),
			FileStruct.m_atime.GetDay(),
			FileStruct.m_atime.GetHour(),
			FileStruct.m_atime.GetMinute(),
			FileStruct.m_atime.GetSecond());
		m_visit.SetWindowTextW(m_strVisit);
		File.Close();
	}

}

void CFileTimeNewDlg::OnBnClickedSave()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//CFile File(m_FileName,CFile::modeReadWrite);
	CFileStatus FileStruct;
	int year,month,day,hour,minute,second;

	//File.Close();
	CFile::GetStatus(m_FileName,FileStruct);

	//�ļ�����ʱ���޸�
	m_create.GetWindowTextW(m_strCreate);
	swscanf(m_strCreate,_T("%u-%u-%u %u:%u:%u"),
		&year,&month,&day,&hour,&minute,&second);
	CTime m_cTime(year,month,day,hour,minute,second);
	FileStruct.m_ctime=m_cTime;

	//�ļ�����ʱ���޸�
	m_visit.GetWindowTextW(m_strVisit);
	swscanf(m_strVisit,_T("%u-%u-%u %u:%u:%u"),
		&year,&month,&day,&hour,&minute,&second);
	CTime m_aTime(year,month,day,hour,minute,second);
	FileStruct.m_atime=m_aTime;

	//�ļ��޸�ʱ���޸�
	m_write.GetWindowTextW(m_strWrite);
	swscanf(m_strWrite,_T("%u-%u-%u %u:%u:%u"),
		&year,&month,&day,&hour,&minute,&second);
	CTime m_mTime(year,month,day,hour,minute,second);
	FileStruct.m_mtime=m_mTime;

	CFile::SetStatus(m_FileName,FileStruct);
}

void CFileTimeNewDlg::OnBnClickedReadme()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	MessageBox(L"�������ʱ�������1970-1-1��2038-1-18֮�䣬������򼴽�����\n"
		L"ʱ���ʽΪXXXX-XX-XX XX:XX:XX",L"˵��",MB_ICONINFORMATION);
}
