#include "CCodeMeasurement.h"

std::deque<CCodeMeasurement> CodeMeasurements;

CCodeMeasurement::CCodeMeasurement(
	IN const CCodeMeasurement& other
)
{
	szName = other.szName;
	fDeltaTime = other.fDeltaTime;
}

CCodeMeasurement::CCodeMeasurement(
	IN const char* name
)
{
	szName = std::string(name);
}

NORETVOID CCodeMeasurement::End(
	NOPARAMS
)
{
	fDeltaTime = std::chrono::duration_cast<std::chrono::duration<double>>(
		std::chrono::high_resolution_clock::now() - MeasureStart).count();
}

const double CCodeMeasurement::GetDeltaTime(
	NOPARAMS
) const
{
	return fDeltaTime;
}

const char* const CCodeMeasurement::GetName(
	NOPARAMS
) const
{
	return szName.c_str();
}