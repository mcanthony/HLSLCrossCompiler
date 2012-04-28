
typedef unsigned int uint32_t;
typedef unsigned char uint8_t;

typedef enum
{
    PIXEL_SHADER,
    VERTEX_SHADER,
    GEOMETRY_SHADER,
    HULL_SHADER,
    DOMAIN_SHADER,
    COMPUTE_SHADER,
} SHADER_TYPE;

SHADER_TYPE DecodeShaderType(uint32_t ui32Token)
{
	return (SHADER_TYPE)((ui32Token & 0xffff0000) >> 16);
}

uint32_t DecodeProgramMajorVersion(uint32_t ui32Token)
{
    return (ui32Token & 0x000000f0) >> 4;
}

uint32_t DecodeProgramMinorVersion(uint32_t ui32Token)
{
    return (ui32Token & 0x0000000f);
}

uint32_t DecodeInstructionLength(uint32_t ui32Token)
{
    return (ui32Token & 0x7f000000) >> 24;
}

uint32_t DecodeIsOpcodeExtended(uint32_t ui32Token)
{
    return (ui32Token & 0x80000000) >> 31;
}

typedef enum
{
    OPCODE_ADD,
    OPCODE_AND,
    OPCODE_BREAK,
    OPCODE_BREAKC,
    OPCODE_CALL,
    OPCODE_CALLC,
    OPCODE_CASE,
    OPCODE_CONTINUE,
    OPCODE_CONTINUEC,
    OPCODE_CUT,
    OPCODE_DEFAULT,
    OPCODE_DERIV_RTX,
    OPCODE_DERIV_RTY,
    OPCODE_DISCARD,
    OPCODE_DIV,
    OPCODE_DP2,
    OPCODE_DP3,
    OPCODE_DP4,
    OPCODE_ELSE,
    OPCODE_EMIT,
    OPCODE_EMITTHENCUT,
    OPCODE_ENDIF,
    OPCODE_ENDLOOP,
    OPCODE_ENDSWITCH,
    OPCODE_EQ,
    OPCODE_EXP,
    OPCODE_FRC,
    OPCODE_FTOI,
    OPCODE_FTOU,
    OPCODE_GE,
    OPCODE_IADD,
    OPCODE_IF,
    OPCODE_IEQ,
    OPCODE_IGE,
    OPCODE_ILT,
    OPCODE_IMAD,
    OPCODE_IMAX,
    OPCODE_IMIN,
    OPCODE_IMUL,
    OPCODE_INE,
    OPCODE_INEG,
    OPCODE_ISHL,
    OPCODE_ISHR,
    OPCODE_ITOF,
    OPCODE_LABEL,
    OPCODE_LD,
    OPCODE_LD_MS,
    OPCODE_LOG,
    OPCODE_LOOP,
    OPCODE_LT,
    OPCODE_MAD,
    OPCODE_MIN,
    OPCODE_MAX,
    OPCODE_CUSTOMDATA,
    OPCODE_MOV,
    OPCODE_MOVC,
    OPCODE_MUL,
    OPCODE_NE,
    OPCODE_NOP,
    OPCODE_NOT,
    OPCODE_OR,
    OPCODE_RESINFO,
    OPCODE_RET,
    OPCODE_RETC,
    OPCODE_ROUND_NE,
    OPCODE_ROUND_NI,
    OPCODE_ROUND_PI,
    OPCODE_ROUND_Z,
    OPCODE_RSQ,
    OPCODE_SAMPLE,
    OPCODE_SAMPLE_C,
    OPCODE_SAMPLE_C_LZ,
    OPCODE_SAMPLE_L,
    OPCODE_SAMPLE_D,
    OPCODE_SAMPLE_B,
    OPCODE_SQRT,
    OPCODE_SWITCH,
    OPCODE_SINCOS,
    OPCODE_UDIV,
    OPCODE_ULT,
    OPCODE_UGE,
    OPCODE_UMUL,
    OPCODE_UMAD,
    OPCODE_UMAX,
    OPCODE_UMIN,
    OPCODE_USHR,
    OPCODE_UTOF,
    OPCODE_XOR,
    OPCODE_DCL_RESOURCE, // DCL* opcodes have
    OPCODE_DCL_CONSTANT_BUFFER, // custom operand formats.
    OPCODE_DCL_SAMPLER,
    OPCODE_DCL_INDEX_RANGE,
    OPCODE_DCL_GS_OUTPUT_PRIMITIVE_TOPOLOGY,
    OPCODE_DCL_GS_INPUT_PRIMITIVE,
    OPCODE_DCL_MAX_OUTPUT_VERTEX_COUNT,
    OPCODE_DCL_INPUT,
    OPCODE_DCL_INPUT_SGV,
    OPCODE_DCL_INPUT_SIV,
    OPCODE_DCL_INPUT_PS,
    OPCODE_DCL_INPUT_PS_SGV,
    OPCODE_DCL_INPUT_PS_SIV,
    OPCODE_DCL_OUTPUT,
    OPCODE_DCL_OUTPUT_SGV,
    OPCODE_DCL_OUTPUT_SIV,
    OPCODE_DCL_TEMPS,
    OPCODE_DCL_INDEXABLE_TEMP,
    OPCODE_DCL_GLOBAL_FLAGS,

// -----------------------------------------------

    OPCODE_RESERVED0,
    
// ---------- DX 10.1 op codes---------------------

    OPCODE_LOD,
    OPCODE_GATHER4,
    OPCODE_SAMPLE_POS,
    OPCODE_SAMPLE_INFO,

// -----------------------------------------------

    // This should be 10.1's version of NUM_OPCODES
    OPCODE_RESERVED1,

// ---------- DX 11 op codes---------------------
    OPCODE_HS_DECLS, // token marks beginning of HS sub-shader
    OPCODE_HS_CONTROL_POINT_PHASE, // token marks beginning of HS sub-shader
    OPCODE_HS_FORK_PHASE, // token marks beginning of HS sub-shader
    OPCODE_HS_JOIN_PHASE, // token marks beginning of HS sub-shader

    OPCODE_EMIT_STREAM,
    OPCODE_CUT_STREAM,
    OPCODE_EMITTHENCUT_STREAM,
    OPCODE_INTERFACE_CALL,

    OPCODE_BUFINFO,
    OPCODE_DERIV_RTX_COARSE,
    OPCODE_DERIV_RTX_FINE,
    OPCODE_DERIV_RTY_COARSE,
    OPCODE_DERIV_RTY_FINE,
    OPCODE_GATHER4_C,
    OPCODE_GATHER4_PO,
    OPCODE_GATHER4_PO_C,
    OPCODE_RCP,
    OPCODE_F32TOF16,
    OPCODE_F16TOF32,
    OPCODE_UADDC,
    OPCODE_USUBB,
    OPCODE_COUNTBITS,
    OPCODE_FIRSTBIT_HI,
    OPCODE_FIRSTBIT_LO,
    OPCODE_FIRSTBIT_SHI,
    OPCODE_UBFE,
    OPCODE_IBFE,
    OPCODE_BFI,
    OPCODE_BFREV,
    OPCODE_SWAPC,

    OPCODE_DCL_STREAM,
    OPCODE_DCL_FUNCTION_BODY,
    OPCODE_DCL_FUNCTION_TABLE,
    OPCODE_DCL_INTERFACE,
    
    OPCODE_DCL_INPUT_CONTROL_POINT_COUNT,
    OPCODE_DCL_OUTPUT_CONTROL_POINT_COUNT,
    OPCODE_DCL_TESS_DOMAIN,
    OPCODE_DCL_TESS_PARTITIONING,
    OPCODE_DCL_TESS_OUTPUT_PRIMITIVE,
    OPCODE_DCL_HS_MAX_TESSFACTOR,
    OPCODE_DCL_HS_FORK_PHASE_INSTANCE_COUNT,
    OPCODE_DCL_HS_JOIN_PHASE_INSTANCE_COUNT,

    OPCODE_DCL_THREAD_GROUP,
    OPCODE_DCL_UNORDERED_ACCESS_VIEW_TYPED,
    OPCODE_DCL_UNORDERED_ACCESS_VIEW_RAW,
    OPCODE_DCL_UNORDERED_ACCESS_VIEW_STRUCTURED,
    OPCODE_DCL_THREAD_GROUP_SHARED_MEMORY_RAW,
    OPCODE_DCL_THREAD_GROUP_SHARED_MEMORY_STRUCTURED,
    OPCODE_DCL_RESOURCE_RAW,
    OPCODE_DCL_RESOURCE_STRUCTURED,
    OPCODE_LD_UAV_TYPED,
    OPCODE_STORE_UAV_TYPED,
    OPCODE_LD_RAW,
    OPCODE_STORE_RAW,
    OPCODE_LD_STRUCTURED,
    OPCODE_STORE_STRUCTURED,
    OPCODE_ATOMIC_AND,
    OPCODE_ATOMIC_OR,
    OPCODE_ATOMIC_XOR,
    OPCODE_ATOMIC_CMP_STORE,
    OPCODE_ATOMIC_IADD,
    OPCODE_ATOMIC_IMAX,
    OPCODE_ATOMIC_IMIN,
    OPCODE_ATOMIC_UMAX,
    OPCODE_ATOMIC_UMIN,
    OPCODE_IMM_ATOMIC_ALLOC,
    OPCODE_IMM_ATOMIC_CONSUME,
    OPCODE_IMM_ATOMIC_IADD,
    OPCODE_IMM_ATOMIC_AND,
    OPCODE_IMM_ATOMIC_OR,
    OPCODE_IMM_ATOMIC_XOR,
    OPCODE_IMM_ATOMIC_EXCH,
    OPCODE_IMM_ATOMIC_CMP_EXCH,
    OPCODE_IMM_ATOMIC_IMAX,
    OPCODE_IMM_ATOMIC_IMIN,
    OPCODE_IMM_ATOMIC_UMAX,
    OPCODE_IMM_ATOMIC_UMIN,   
    OPCODE_SYNC,
    
    OPCODE_DADD,
    OPCODE_DMAX,
    OPCODE_DMIN,
    OPCODE_DMUL,
    OPCODE_DEQ,
    OPCODE_DGE,
    OPCODE_DLT,
    OPCODE_DNE,
    OPCODE_DMOV,
    OPCODE_DMOVC,
    OPCODE_DTOF,
    OPCODE_FTOD,

    OPCODE_EVAL_SNAPPED,
    OPCODE_EVAL_SAMPLE_INDEX,
    OPCODE_EVAL_CENTROID,
    
    OPCODE_DCL_GS_INSTANCE_COUNT,

    NUM_OPCODES
} OPCODE_TYPE;

OPCODE_TYPE DecodeOpcodeType(uint32_t ui32Token)
{
    return (OPCODE_TYPE)(ui32Token & 0x00007ff);
}

typedef enum
{
    INDEX_0D,
    INDEX_1D,
    INDEX_2D,
    INDEX_3D,
} OPERAND_INDEX_DIMENSION;

OPERAND_INDEX_DIMENSION DecodeOperandIndexDimension(uint32_t ui32Token)
{
	return (OPERAND_INDEX_DIMENSION)((ui32Token & 0x00300000) >> 20);
}