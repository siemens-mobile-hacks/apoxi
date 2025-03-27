/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(TRACE_HPP)
#define TRACE_HPP

#include <Kernel/Os/InternalTracer.hpp>
#include <Kernel/ApplicationTracer.hpp>
#include <Kernel/FunctionTracer.hpp>


#if defined(APOXI_TRACE_DISABLED)

#undef APOXI_TRACE
#undef APOXI_TRACE_LEVEL_2
#undef APOXI_TRACE_LEVEL_3
#undef APOXI_TRACE_MEM

#else

// per default, Apoxi Tracing is enabled
#undef APOXI_TRACE
#define APOXI_TRACE

#endif



#if defined(APOXI_TRACE) | defined(APOXI_TRACE_LEVEL_2) | defined(APOXI_TRACE_LEVEL_3)


typedef _ApplicationTracer AppTracer;
typedef _FunctionTracer<InternalTracer::Always> Tracer;

typedef _FunctionTracer<InternalTracer::Adc> AdcTracer;
typedef _FunctionTracer<InternalTracer::Apc> ApcTracer;
typedef _FunctionTracer<InternalTracer::Asc> AscTracer;
typedef _FunctionTracer<InternalTracer::Aux> AuxTracer;
typedef _FunctionTracer<InternalTracer::Gui> GuiTracer;
typedef _FunctionTracer<InternalTracer::Kernel> KernelTracer;
typedef _FunctionTracer<InternalTracer::Socket> SocketTracer;
typedef _FunctionTracer<InternalTracer::Mmi> MmiTracer;
typedef _FunctionTracer<InternalTracer::App1> App1Tracer;
typedef _FunctionTracer<InternalTracer::App2> App2Tracer;
typedef _FunctionTracer<InternalTracer::App3> App3Tracer;
typedef _FunctionTracer<InternalTracer::App4> App4Tracer;

#else

typedef _NullApplicationTracer AppTracer;
typedef _NullFunctionTracer Tracer;

typedef _NullFunctionTracer AdcTracer;
typedef _NullFunctionTracer ApcTracer;
typedef _NullFunctionTracer AscTracer;
typedef _NullFunctionTracer AuxTracer;
typedef _NullFunctionTracer GuiTracer;
typedef _NullFunctionTracer KernelTracer;
typedef _NullFunctionTracer SocketTracer;
typedef _NullFunctionTracer MmiTracer;
typedef _NullFunctionTracer App1Tracer;
typedef _NullFunctionTracer App2Tracer;
typedef _NullFunctionTracer App3Tracer;
typedef _NullFunctionTracer App4Tracer;

#endif




#if defined(APOXI_TRACE_LEVEL_2) | defined(APOXI_TRACE_LEVEL_3)

#if !defined(APOXI_TRACE)
#define APOXI_TRACE
#endif

typedef _FunctionTracer<InternalTracer::Adc> AdcTracerLevel2;
typedef _FunctionTracer<InternalTracer::Apc> ApcTracerLevel2;
typedef _FunctionTracer<InternalTracer::Asc> AscTracerLevel2;
typedef _FunctionTracer<InternalTracer::Aux> AuxTracerLevel2;
typedef _FunctionTracer<InternalTracer::Gui> GuiTracerLevel2;
typedef _FunctionTracer<InternalTracer::Kernel> KernelTracerLevel2;
typedef _FunctionTracer<InternalTracer::Socket> SocketTracerLevel2;
typedef _FunctionTracer<InternalTracer::Mmi> MmiTracerLevel2;
typedef _FunctionTracer<InternalTracer::App1> App1TracerLevel2;
typedef _FunctionTracer<InternalTracer::App2> App2TracerLevel2;
typedef _FunctionTracer<InternalTracer::App3> App3TracerLevel2;
typedef _FunctionTracer<InternalTracer::App4> App4TracerLevel2;

#else

typedef _NullFunctionTracer AdcTracerLevel2;
typedef _NullFunctionTracer ApcTracerLevel2;
typedef _NullFunctionTracer AscTracerLevel2;
typedef _NullFunctionTracer AuxTracerLevel2;
typedef _NullFunctionTracer GuiTracerLevel2;
typedef _NullFunctionTracer KernelTracerLevel2;
typedef _NullFunctionTracer SocketTracerLevel2;
typedef _NullFunctionTracer MmiTracerLevel2;
typedef _NullFunctionTracer App1TracerLevel2;
typedef _NullFunctionTracer App2TracerLevel2;
typedef _NullFunctionTracer App3TracerLevel2;
typedef _NullFunctionTracer App4TracerLevel2;

#endif




#if defined(APOXI_TRACE_LEVEL_3)

#if !defined(APOXI_TRACE)
#define APOXI_TRACE
#endif

typedef _FunctionTracer<InternalTracer::Adc> AdcTracerLevel3;
typedef _FunctionTracer<InternalTracer::Apc> ApcTracerLevel3;
typedef _FunctionTracer<InternalTracer::Asc> AscTracerLevel3;
typedef _FunctionTracer<InternalTracer::Aux> AuxTracerLevel3;
typedef _FunctionTracer<InternalTracer::Gui> GuiTracerLevel3;
typedef _FunctionTracer<InternalTracer::Kernel> KernelTracerLevel3;
typedef _FunctionTracer<InternalTracer::Socket> SocketTracerLevel3;
typedef _FunctionTracer<InternalTracer::Mmi> MmiTracerLevel3;
typedef _FunctionTracer<InternalTracer::App1> App1TracerLevel3;
typedef _FunctionTracer<InternalTracer::App2> App2TracerLevel3;
typedef _FunctionTracer<InternalTracer::App3> App3TracerLevel3;
typedef _FunctionTracer<InternalTracer::App4> App4TracerLevel3;

#else

typedef _NullFunctionTracer AdcTracerLevel3;
typedef _NullFunctionTracer ApcTracerLevel3;
typedef _NullFunctionTracer AscTracerLevel3;
typedef _NullFunctionTracer AuxTracerLevel3;
typedef _NullFunctionTracer GuiTracerLevel3;
typedef _NullFunctionTracer KernelTracerLevel3;
typedef _NullFunctionTracer SocketTracerLevel3;
typedef _NullFunctionTracer MmiTracerLevel3;
typedef _NullFunctionTracer App1TracerLevel3;
typedef _NullFunctionTracer App2TracerLevel3;
typedef _NullFunctionTracer App3TracerLevel3;
typedef _NullFunctionTracer App4TracerLevel3;

#endif

#endif // TRACE_HPP


