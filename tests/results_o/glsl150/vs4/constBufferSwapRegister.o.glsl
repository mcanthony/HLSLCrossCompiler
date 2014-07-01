#version 150
#extension GL_ARB_shader_bit_encoding : require
struct vec1 {
	float x;
};
struct uvec1 {
	uint x;
};
struct ivec1 {
	int x;
};
uniform struct SecondCBufferVS_Type {
	vec4 world_view_proj[4];
} SecondCBufferVS;
uniform struct FirstCBufferVS_Type {
	vec4 vars;
} FirstCBufferVS;
 in  vec4 dcl_Input0;
vec4 Input0;
 out  vec4 VtxGeoOutput0;
#define Output0 VtxGeoOutput0
vec4 Temp[1];
ivec4 Temp_int[1];
uvec4 Temp_uint[1];
void main()
{
    //--- Start Early Main ---
    Input0 = dcl_Input0;
    //--- End Early Main ---
    //Instruction 0
    //ADD
    Temp_int[0] = floatBitsToInt(Input0 + FirstCBufferVS.vars);
    //Instruction 1
    //DP4
    Output0.x = (vec4(dot(intBitsToFloat(Temp_int[0]), SecondCBufferVS.world_view_proj[0])).x);
    //Instruction 2
    //DP4
    Output0.y = (vec4(dot(intBitsToFloat(Temp_int[0]), SecondCBufferVS.world_view_proj[1])).y);
    //Instruction 3
    //DP4
    Output0.z = (vec4(dot(intBitsToFloat(Temp_int[0]), SecondCBufferVS.world_view_proj[2])).z);
    //Instruction 4
    //DP4
    Output0.w = (vec4(dot(intBitsToFloat(Temp_int[0]), SecondCBufferVS.world_view_proj[3])).w);
    //Instruction 5
    //RET
    return;
}
