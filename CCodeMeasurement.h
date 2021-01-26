#ifndef _C_CODE_MEASUREMENT_H_
#define _C_CODE_MEASUREMENT_H_

#pragma once

#include <string>
#include <deque>
#include <chrono>

#define NORETVOID		[[noreturn]] void
#define IN
#define OUT
#define NOPARAMS

class CCodeMeasurement
{
private:
	std::string szName = std::string("<unknown>");
	double fDeltaTime = 0.0f;

	// We've started measuring after the object has been constructed
	std::chrono::high_resolution_clock::time_point MeasureStart = std::chrono::high_resolution_clock::now();
public:

	CCodeMeasurement(IN const CCodeMeasurement& other);
	CCodeMeasurement(IN const char* name);

public:
	NORETVOID End(NOPARAMS);
public:
	const double GetDeltaTime(NOPARAMS) const;
	const char* const GetName(NOPARAMS) const;
};

extern std::deque<CCodeMeasurement> CodeMeasurements;

#define CODE_MEASUREMENT_START(name) 					\
	CCodeMeasurement code_measure_##name = { #name }

#define CODE_MEASUREMENT_END(name)						\
	code_measure_##name.End();							\
	CodeMeasurements.push_back(code_measure_##name)

#endif
