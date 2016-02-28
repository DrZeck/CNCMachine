#ifndef __PID_H_
#define __PID_H_

typedef struct {
	float pGain;        // ���������������� ����������
	float iTime;        // ����� ��������������
	float dTime;         // ����� ����������������
	float iMax;    // �������
	float iMin;// � �������� ��� ������������� ��������
	float iMaxError;

	float refValue;
	float refAmplitude;
	float refTime;
	float refAmplitudeKoef;
	float refTimeKoef;

	int resultScale; // �� ��� ��������� ���������
	int minResultValue;	// ����������� ��� ��������� �������� � ��������
	int maxResultValue; // ����������� ��� ��������� �������� � ���������
	int lockValue; // ��� ����� ������� ���������� �������� ������������ �����

	float lastValue;                  // ��������� ��������
	float iState;                  // ������������ ��������
	int lock; 				// ����� �� �������� ������������ ������������ �� ����� ���������
	int lockTime;
	float dFilter;
	int outFilter;
} PID;

void PID_Init(PID * pid, int minValue, int maxValue, int lockValue);
int PID_UpdatePID(PID * pid, float error, float value);
void PID_PreparePID(PID* pid, float currentValue, float targetValue);
void PID_ResetPID(PID* pid);
void PID_CalibrationData(PID* pid, float refValue, float value, float amplitude, float time);

#endif // __PID_H_
