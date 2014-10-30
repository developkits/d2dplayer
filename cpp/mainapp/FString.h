#include <string>
#include "inttypes.h"
#include "Windows.h"
using namespace std;

class FString
{
	enum Bit{
		BIT_
	};
public:
	FString();
	FString( LPCSTR p );
	FString( LPWCH wp );
	~FString();
	string toStdString();
	wstring toStdWString(); 
private:
	void stdtostdw();
private:
	uint32_t		m_uFlag;		//���λ��ʶstr or wstr,�θ�λ�����Ƿ�Ϊnew,����30λ������
	void*			m_pStr;
};
