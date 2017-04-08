#ifndef __COOLPROP_LIB_H__
#define __COOLPROP_LIB_H__ 1
#ifdef __cplusplus
extern "C" {
#endif


#if defined(_WIN32) || defined(__WIN32__) || defined(_WIN64) || defined(__WIN64__)
#    define __CPISWINDOWS__
#else defined(__linux) || defined(__unix) || defined(__posix)
#    define __CPISLINUX__
#endif

#if defined(__CPISWINDOWS__)
#    define CPCALLCONV __stdcall
#else
#    define CPCALLCONV
#endif

/**
* \overload
* \sa \ref CoolProp::Props1SI(std::string, std::string)
* 
* \note If there is an error, a huge value will be returned, you can get the error message by doing something like get_global_param_string("errstring",output)
*/
typedef double (CPCALLCONV *Props1SI)(const char *Refrigerant, const char *output);
/**
*\overload
*\sa \ref CoolProp::PropsSI(const std::string &, const std::string &, double, const std::string &, double, const std::string&)
* 
* \note If there is an error, a huge value will be returned, you can get the error message by doing something like get_global_param_string("errstring",output)
*/
typedef double (CPCALLCONV *PropsSI)(const char *output, const char *Name1, double InputValue1, 
                const char *Name2, double InputValue2, const char *Refrigerant);
/**
*\overload
*\sa \ref CoolProp::PhaseSI(const std::string &, double, const std::string &, double, const std::string&)
* 
* \note This function returns the phase string in pre-allocated phase variable.  If buffer is not large enough, no copy is made
*/
typedef long (CPCALLCONV *PhaseSI)(const char *Name1, double Prop1, const char *Name2, 
               double Prop2, const char *Ref, char *phase, int n);
/**
*\overload
*\sa \ref CoolProp::get_global_param_string
* 
* @returns error_code 1 = Ok 0 = error
* 
* \note This function returns the output string in pre-allocated char buffer.  If buffer is not large enough, no copy is made
*/
typedef long (CPCALLCONV *get_global_param_string)(const char *param, char *Output, int n);
/**
* \overload
* \sa \ref CoolProp::get_parameter_information_string
* \note This function returns the output string in pre-allocated char buffer.  If buffer is not large enough, no copy is made
* 
* @returns error_code 1 = Ok 0 = error
*/
typedef long (CPCALLCONV *get_parameter_information_string)(const char *key, char *Output, int n);
/** 
* \overload
* \sa \ref CoolProp::get_fluid_param_string
* 
* @returns error_code 1 = Ok 0 = error
*/
typedef long (CPCALLCONV *get_fluid_param_string)(const char *fluid, const char *param, char *Output, int n);
/**
* \overload
* \sa \ref CoolProp::set_reference_stateS
* @returns error_code 1 = Ok 0 = error
*/
typedef int (CPCALLCONV *set_reference_stateS)(const char *Ref, const char *reference_state);
/**
* \overload
* \sa \ref CoolProp::set_reference_stateD
* @returns error_code 1 = Ok 0 = error
*/
typedef int (CPCALLCONV *set_reference_stateD)(const char *Ref, double T, double rho, double h0, double s0);
/** \brief FORTRAN 77 style wrapper of the PropsSI function
* \overload
* \sa \ref CoolProp::PropsSI(const std::string &, const std::string &, double, const std::string &, double, const std::string&)
* 
* \note If there is an error, a huge value will be returned, you can get the error message by doing something like get_global_param_string("errstring",output)
*/
typedef void (CPCALLCONV *propssi_)(const char *Output, const char *Name1, const double *Prop1, const char *Name2, 
              const double *Prop2, const char * Ref, double *output);
/* Convert from degrees Fahrenheit to Kelvin (useful primarily for testing)*/
typedef double (CPCALLCONV *F2K)(double T_F);
/* Convert from Kelvin to degrees Fahrenheit (useful primarily for testing)*/
typedef double (CPCALLCONV *K2F)(double T_K);
/** \brief Get the index for a parameter "T", "P", etc.
* 
* @returns index The index as a long.  If input is invalid, returns -1
*/
typedef long (CPCALLCONV *get_param_index)(const char *param);
/** \brief Get the index for an input pair for AbstractState.update function
* 
* @returns index The index as a long.  If input is invalid, returns -1
*/
typedef long (CPCALLCONV *get_input_pair_index)(const char *param);
/** \brief Redirect all output that would go to console (stdout) to a file
*/
typedef long (CPCALLCONV *redirect_stdout)(const char *file);
/* ---------------------------------
*  Getter and setter for debug level
*  ---------------------------------
*
*  Get the debug level
*  @returns level The level of the verbosity for the debugging output (0-10) 0: no debgging output
*/
typedef int (CPCALLCONV *get_debug_level)(void);
/* Set the debug level
*  @param level The level of the verbosity for the debugging output (0-10) 0: no debgging output
*/
typedef void (CPCALLCONV *set_debug_level)(int level);
/* \brief Extract a value from the saturation ancillary
* 
* @param fluid_name The name of the fluid to be used - HelmholtzEOS backend only
* @param output The desired output variable ("P" for instance for pressure)
* @param Q The quality, 0 or 1
* @param input The input variable ("T")
* @param value The input value
*/
typedef double (CPCALLCONV *saturation_ancillary)(const char *fluid_name, const char *output, int Q, const char *input, double value);
/* ---------------------------------
*          Humid Air Properties
*  ---------------------------------
*/
/** \brief DLL wrapper of the HAPropsSI function
* \sa \ref HumidAir::HAPropsSI(const char *OutputName, const char *Input1Name, double Input1, const char *Input2Name, double Input2, const char *Input3Name, double Input3);
* 
* \note If there is an error, a huge value will be returned, you can get the error message by doing something like get_global_param_string("errstring",output)
*/
typedef double (CPCALLCONV *HAPropsSI)(const char *Output, const char *Name1, double Prop1, const char *Name2, double Prop2, const char *Name3, double Prop3);
/** \brief DLL wrapper of the cair_sat function
* \sa \ref HumidAir::cair_sat(double);
*/
typedef double (CPCALLCONV *cair_sat)(double T);
/** \brief FORTRAN 77 style wrapper of the HAPropsSI function
* \sa \ref HumidAir::HAPropsSI(const char *OutputName, const char *Input1Name, double Input1, const char *Input2Name, double Input2, const char *Input3Name, double Input3);
* 
* \note If there is an error, a huge value will be returned, you can get the error message by doing something like get_global_param_string("errstring",output)
*/
typedef void (CPCALLCONV *hapropssi_)(const char *Output, const char *Name1, const double *Prop1, const char *Name2, const double *Prop2, const char *Name3, const double *Prop3, double *output);
/** \brief DLL wrapper of the HAProps function
* 
* \warning DEPRECATED!!
* \sa \ref HumidAir::HAProps(const char *OutputName, const char *Input1Name, double Input1, const char *Input2Name, double Input2, const char *Input3Name, double Input3);
* 
* \note If there is an error, a huge value will be returned, you can get the error message by doing something like get_global_param_string("errstring",output)
*/
typedef double (CPCALLCONV *HAProps)(const char *Output, const char *Name1, double Prop1, const char *Name2, double Prop2, const char *Name3, double Prop3);
/** \brief FORTRAN 77 style wrapper of the HAProps function
*
* \warning DEPRECATED!!
* \sa \ref HumidAir::HAProps(const char *OutputName, const char *Input1Name, double Input1, const char *Input2Name, double Input2, const char *Input3Name, double Input3);
* 
* \note If there is an error, a huge value will be returned, you can get the error message by doing something like get_global_param_string("errstring",output)
*/
typedef void (CPCALLCONV *haprops_)(const char *Output, const char *Name1, const double *Prop1, const char *Name2, const double *Prop2, const char *Name3, const double *Prop3, double *output);
/* ---------------------------------
*         Low-level access
*  ---------------------------------
*/  
/**
* @brief Generate an AbstractState instance, return an integer handle to the state class generated to be used in the other low-level accessor functions
* @param backend The backend you will use, "HEOS", "REFPROP", etc.
* @param fluids '&' delimited list of fluids
* @param errcode The errorcode that is returned (0 = no error, !0 = error)
* @param message_buffer A buffer for the error code
* @param buffer_length The length of the buffer for the error code
* @return A handle to the state class generated
*/
typedef long (CPCALLCONV *AbstractState_factory)(const char* backend, const char* fluids, long *errcode, char *message_buffer, const long buffer_length);
/**
* @brief Release a state class generated by the low-level interface wrapper
* @param handle The integer handle for the state class stored in memory
* @param errcode The errorcode that is returned (0 = no error, !0 = error)
* @param message_buffer A buffer for the error code
* @param buffer_length The length of the buffer for the error code
* @return 
*/
typedef void (CPCALLCONV *AbstractState_free)(const long handle, long *errcode, char *message_buffer, const long buffer_length);
/**
* @brief Set the fractions (mole, mass, volume) for the AbstractState
* @param handle The integer handle for the state class stored in memory
* @param fractions The array of fractions
* @param N The length of the fractions array
* @param errcode The errorcode that is returned (0 = no error, !0 = error)
* @param message_buffer A buffer for the error code
* @param buffer_length The length of the buffer for the error code
* @return 
*/
typedef void (CPCALLCONV *AbstractState_set_fractions)(const long handle, const double* fractions, const long N, long *errcode, char *message_buffer, const long buffer_length);
/**
* @brief Update the state of the AbstractState
* @param handle The integer handle for the state class stored in memory
* @param input_pair The integer value for the input pair obtained from XXXXXXXXXXXXXXXX
* @param value1 The first input value
* @param value2 The second input value
* @param errcode The errorcode that is returned (0 = no error, !0 = error)
* @param message_buffer A buffer for the error code
* @param buffer_length The length of the buffer for the error code
* @return 
*/
typedef void (CPCALLCONV *AbstractState_update)(const long handle, const long input_pair, const double value1, const double value2, long *errcode, char *message_buffer, const long buffer_length);
/**
* @brief Get an output value from the AbstractState using an integer value for the desired output value
* @param handle The integer handle for the state class stored in memory
* @param param The integer value for the parameter you want
* @param errcode The errorcode that is returned (0 = no error, !0 = error)
* @param message_buffer A buffer for the error code
* @param buffer_length The length of the buffer for the error code
* @return 
*/
typedef double (CPCALLCONV *AbstractState_keyed_output)(const long handle, const long param, long *errcode, char *message_buffer, const long buffer_length);
/**
* @brief Calculate a saturation derivative from the AbstractState using integer values for the desired parameters
* @param handle The integer handle for the state class stored in memory
* @param Of The parameter of which the derivative is being taken
* @param Wrt The derivative with with respect to this parameter
* @param errcode The errorcode that is returned (0 = no error, !0 = error)
* @param message_buffer A buffer for the error code
* @param buffer_length The length of the buffer for the error code
* @return
*/
typedef double (CPCALLCONV *AbstractState_first_saturation_deriv)(const long handle, const long Of, const long Wrt, long *errcode, char *message_buffer, const long buffer_length);
/**
* @brief Calculate the first partial derivative in homogeneous phases from the AbstractState using integer values for the desired parameters
* @param handle The integer handle for the state class stored in memory
* @param Of The parameter of which the derivative is being taken
* @param Wrt The derivative with with respect to this parameter
* @param Constant The parameter that is not affected by the derivative
* @param errcode The errorcode that is returned (0 = no error, !0 = error)
* @param message_buffer A buffer for the error code
* @param buffer_length The length of the buffer for the error code
* @return
*/
typedef double (CPCALLCONV *AbstractState_first_partial_deriv)(const long handle, const long Of, const long Wrt, const long Constant, long *errcode, char *message_buffer, const long buffer_length);
/**
* @brief Update the state of the AbstractState and get an output value five common outputs (temperature, pressure, molar density, molar enthalpy and molar entropy)
* @brief from the AbstractState using pointers as inputs and output to allow array computation.
* @param handle The integer handle for the state class stored in memory
* @param input_pair The integer value for the input pair obtained from get_input_pair_index
* @param value1 The pointer to the array of the first input parameters
* @param value2 The pointer to the array of the second input parameters
* @param length The number of elements stored in the arrays (both inputs and outputs MUST be the same length)
* @param T The pointer to the array of temperature
* @param p The pointer to the array of pressure
* @param rhomolar The pointer to the array of molar density
* @param hmolar The pointer to the array of molar enthalpy
* @param smolar The pointer to the array of molar entropy
* @param errcode The errorcode that is returned (0 = no error, !0 = error)
* @param message_buffer A buffer for the error code
* @param buffer_length The length of the buffer for the error code
* @return
*
* @note If there is an error in an update call for one of the inputs, no change in the output array will be made
*/
typedef void (CPCALLCONV *AbstractState_update_and_common_out)(const long handle, const long input_pair, const double* value1, const double* value2, const long length, double* T, double* p, 
              double* rhomolar, double* hmolar, double* smolar, long *errcode, char *message_buffer, const long buffer_length);
/**
* @brief Update the state of the AbstractState and get an output value five common outputs (temperature, pressure, molar density, molar enthalpy and molar entropy)
* @brief from the AbstractState using pointers as inputs and output to allow array computation.
* @param handle The integer handle for the state class stored in memory
* @param input_pair The integer value for the input pair obtained from get_input_pair_index
* @param value1 The pointer to the array of the first input parameters
* @param value2 The pointer to the array of the second input parameters
* @param length The number of elements stored in the arrays (both inputs and outputs MUST be the same length)
* @param outputs The 5-element vector of indices for the outputs desired
* @param out1 The pointer to the array for the first output
* @param out2 The pointer to the array for the second output
* @param out3 The pointer to the array for the third output
* @param out4 The pointer to the array for the fourth output
* @param out5 The pointer to the array for the fifth output
* @param errcode The errorcode that is returned (0 = no error, !0 = error)
* @param message_buffer A buffer for the error code
* @param buffer_length The length of the buffer for the error code
* @return
*
* @note If there is an error in an update call for one of the inputs, no change in the output array will be made
*/
typedef void (CPCALLCONV *AbstractState_update_and_5_out)(const long handle, const long input_pair, const double* value1, const double* value2, const long length, long *outputs, double* out1, 
              double* out2, double* out3, double* out4, double* out5, long *errcode, char *message_buffer, const long buffer_length);
/* *************************************************************************************
*  *************************************************************************************
*  *****************************  DEPRECATED *******************************************
*  *************************************************************************************
*  *************************************************************************************
*/
/**
\overload
\sa \ref Props(const char *Output, const char Name1, double Prop1, const char Name2, double Prop2, const char *Ref)
*/
typedef double (CPCALLCONV *PropsS)(const char *Output, const char *Name1, double Prop1, const char *Name2, double Prop2, const char *Ref);
/**
Works just like \ref CoolProp::PropsSI, but units are in KSI system.  This function is deprecated, no longer supported, and users should transition to using the PropsSI function
*/
typedef double (CPCALLCONV *Props)(const char *Output, const char Name1, double Prop1, const char Name2, double Prop2, const char *Ref);
/**
Works just like \ref CoolProp::Props1SI, but units are in KSI system.  This function is deprecated, no longer supported, and users should transition to using the Props1SI function
*/
typedef double (CPCALLCONV *Props1)(const char *FluidName, const char *Output);

/*function pointer*/
Props1SI Props1SIdll;
PropsSI PropsSIdll;
PhaseSI PhaseSIdll;
get_global_param_string get_global_param_stringdll;
get_parameter_information_string get_parameter_information_stringdll;
get_fluid_param_string get_fluid_param_stringdll;
set_reference_stateS set_reference_stateSdll;
set_reference_stateD set_reference_stateDdll;
propssi_ propssi_dll;
F2K F2Kdll;
K2F K2Fdll;
get_param_index get_param_indexdll;
get_input_pair_index get_input_pair_indexdll;
redirect_stdout redirect_stdoutdll;
get_debug_level get_debug_leveldll;
set_debug_level set_debug_leveldll;
saturation_ancillary saturation_ancillarydll;
HAPropsSI HAPropsSIdll;
cair_sat cair_satdll;
hapropssi_ hapropssi_dll;
HAProps HAPropsdll;
haprops_ haprops_dll;
AbstractState_factory AbstractState_factorydll;
AbstractState_free AbstractState_freedll;
AbstractState_set_fractions AbstractState_set_fractionsdll;
AbstractState_update AbstractState_updatedll;
AbstractState_keyed_output AbstractState_keyed_outputdll;
AbstractState_first_saturation_deriv AbstractState_first_saturation_derivdll;
AbstractState_first_partial_deriv AbstractState_first_partial_derivdll;
AbstractState_update_and_common_out AbstractState_update_and_common_outdll;
AbstractState_update_and_5_out AbstractState_update_and_5_outdll;
PropsS PropsSdll;
Props Propsdll;
Props1 Props1dll;

/*API*/
int CoolPropdllinit(void);
int CloseCoolPropdll(void);
#ifdef __cplusplus
}
#endif
#endif
