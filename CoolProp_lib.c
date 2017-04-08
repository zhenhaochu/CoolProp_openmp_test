#include <stdio.h>
#include <stdlib.h>

#include "CoolProp_lib.h"
#if defined __CPISWINDOWS__
#include <Windows.h>
static HINSTANCE CoolPropdllInstance = NULL;
#else defined __CPISLINUX__
#include <dlfcn.h>
static void *CoolPropdllInstance = NULL;
#endif
void *getFunctionPointer(const char*name)
{
#if defined __CPISWINDOWS__
    return (void *)GetProcAddress(CoolPropdllInstance, name);
#elif defined __CPISLINUX__
    return dlym(CoolPropdllInstance, name);
#else
    return NULL;
#endif
}
int CoolPropdllinit(void)
{
#if defined __CPISWINDOWS__
    CoolPropdllInstance = LoadLibraryA("..\\LIB\\libcoolprop\\CoolProp64.dll");
#else defined __CPISLINUX__
    CoolPropdllInstance = dlopen("..\\LIB\\libcoolprop\\libCoolProp.dll");
#endif
    if(CoolPropdllInstance == NULL) 
    {
        printf("CoolProp dll load error!\n");
        exit(EXIT_FAILURE);
    }
    /*get function pointer address*/
    Props1SIdll = (Props1SI)getFunctionPointer("Props1SI");
    PropsSIdll = (PropsSI)getFunctionPointer("PropsSI");
    PhaseSIdll = (PhaseSI)getFunctionPointer("PhaseSI");
    get_global_param_stringdll = (get_global_param_string)getFunctionPointer("get_global_param_string");
    get_parameter_information_stringdll = (get_parameter_information_string)getFunctionPointer("get_parameter_information_string");
    get_input_pair_indexdll = (get_input_pair_index)getFunctionPointer("get_input_pair_index");
    get_fluid_param_stringdll = (get_fluid_param_string)getFunctionPointer("get_fluid_param_string");
    set_reference_stateSdll = (set_reference_stateS)getFunctionPointer("set_reference_stateS");
    set_reference_stateDdll = (set_reference_stateD)getFunctionPointer("set_reference_stateD");
    propssi_dll = (propssi_)getFunctionPointer("propssi_");
    F2Kdll = (F2K)getFunctionPointer("F2K");
    K2Fdll = (K2F)getFunctionPointer("K2F");
    get_param_indexdll = (get_param_index)getFunctionPointer("get_param_index");
    redirect_stdoutdll = (redirect_stdout)getFunctionPointer("redirect_stdout");
    get_debug_leveldll = (get_debug_level)getFunctionPointer("get_debug_level");
    set_debug_leveldll = (set_debug_level)getFunctionPointer("set_debug_level");
    saturation_ancillarydll = (saturation_ancillary)getFunctionPointer("saturation_ancillary");
    HAPropsSIdll = (HAPropsSI)getFunctionPointer("HAPropsSI");
    cair_satdll = (cair_sat)getFunctionPointer("cair_sat");
    hapropssi_dll = (hapropssi_)getFunctionPointer("hapropssi_");
    HAPropsdll = (HAProps)getFunctionPointer("HAProps");
    haprops_dll = (haprops_)getFunctionPointer("haprops_");
    AbstractState_factorydll = (AbstractState_factory)getFunctionPointer("AbstractState_factory");
    AbstractState_freedll = (AbstractState_free)getFunctionPointer("AbstractState_free");
    AbstractState_set_fractionsdll = (AbstractState_set_fractions)getFunctionPointer("AbstractState_set_fractions");
    AbstractState_updatedll = (AbstractState_update)getFunctionPointer("AbstractState_update");
    AbstractState_keyed_outputdll = (AbstractState_keyed_output)getFunctionPointer("AbstractState_keyed_output");
    AbstractState_first_saturation_derivdll = (AbstractState_first_saturation_deriv)getFunctionPointer("AbstractState_first_saturation_deriv");
    AbstractState_first_partial_derivdll = (AbstractState_first_partial_deriv)getFunctionPointer("AbstractState_first_partial_deriv");
    AbstractState_update_and_common_outdll = (AbstractState_update_and_common_out)getFunctionPointer("AbstractState_update_and_common_out");
    AbstractState_update_and_5_outdll = (AbstractState_update_and_5_out)getFunctionPointer("AbstractState_update_and_5_out");
    PropsSdll = (PropsS)getFunctionPointer("PropsS");
    Propsdll = (Props)getFunctionPointer("Props");
    Props1dll = (Props1)getFunctionPointer("Props1");
    return 0;
}
int CloseCoolPropdll(void)
{
    CoolPropdllInstance = NULL;
    return 0;
}
