/* auto generated by extensions_gl.lua */
/*
 * Copyright (c) 2018-2021, NVIDIA CORPORATION.  All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * SPDX-FileCopyrightText: Copyright (c) 2018-2021 NVIDIA CORPORATION
 * SPDX-License-Identifier: Apache-2.0
 */

/** @DOC_START
# function load_GL
> An OpenGL Extension loader
  
  Provides a subset of OpenGL Extensions generated by `extensions_gl.lua`.
  The framework uses a sanitized OpenGL header that is mostly core functionality.
  `GL/glsubset.h` is generated using a enablelist by the lua script
  from `GL/glcustom.h` (which is mostly based on `glcorearb.h` with some
  additional extensions and features)
@DOC_END */

#pragma once

#define GL_GLEXT_PROTOTYPES
#include <GL/glsubset.h>

typedef void* (* nvGLLoaderGetProcFN)(const char* name);

/* structs */
/* GL_NV_command_list */
typedef struct {
  GLuint  header;
} TerminateSequenceCommandNV;

typedef struct {
  GLuint  header;
} NOPCommandNV;

typedef  struct {
  GLuint  header;
  GLuint  count;
  GLuint  firstIndex;
  GLuint  baseVertex;
} DrawElementsCommandNV;

typedef  struct {
  GLuint  header;
  GLuint  count;
  GLuint  first;
} DrawArraysCommandNV;

typedef  struct {
  GLuint  header;
  GLenum  mode;
  GLuint  count;
  GLuint  instanceCount;
  GLuint  firstIndex;
  GLuint  baseVertex;
  GLuint  baseInstance;
} DrawElementsInstancedCommandNV;

typedef  struct {
  GLuint  header;
  GLenum  mode;
  GLuint  count;
  GLuint  instanceCount;
  GLuint  first;
  GLuint  baseInstance;
} DrawArraysInstancedCommandNV;

typedef struct {
  GLuint  header;
  GLuint  addressLo;
  GLuint  addressHi;
  GLuint  typeSizeInByte;
} ElementAddressCommandNV;

typedef struct {
  GLuint  header;
  GLuint  index;
  GLuint  addressLo;
  GLuint  addressHi;
} AttributeAddressCommandNV;

typedef struct {
  GLuint    header;
  GLushort  index;
  GLushort  stage;
  GLuint    addressLo;
  GLuint    addressHi;
} UniformAddressCommandNV;

typedef struct {
  GLuint  header;
  float   red;
  float   green;
  float   blue;
  float   alpha;
} BlendColorCommandNV;

typedef struct {
  GLuint  header;
  GLuint  frontStencilRef;
  GLuint  backStencilRef;
} StencilRefCommandNV;

typedef struct {
  GLuint  header;
  float   lineWidth;
} LineWidthCommandNV;

typedef struct {
  GLuint  header;
  float   scale;
  float   bias;
} PolygonOffsetCommandNV;

typedef struct {
  GLuint  header;
  float   alphaRef;
} AlphaRefCommandNV;

typedef struct {
  GLuint  header;
  GLuint  x;
  GLuint  y;
  GLuint  width;
  GLuint  height;
} ViewportCommandNV;  /* only ViewportIndex 0 */

typedef struct {
  GLuint  header;
  GLuint  x;
  GLuint  y;
  GLuint  width;
  GLuint  height;
} ScissorCommandNV;   /* only ViewportIndex 0 */

typedef struct {
  GLuint  header;
  GLuint  frontFace;  /* 0 for CW, 1 for CCW */
} FrontFaceCommandNV;


/* loader */

void load_GL(nvGLLoaderGetProcFN fnGetProcAddress);

/* availables */
extern int has_GL_VERSION_1_1;
extern int has_GL_VERSION_1_2;
extern int has_GL_VERSION_1_3;
extern int has_GL_VERSION_1_4;
extern int has_GL_VERSION_1_5;
extern int has_GL_VERSION_2_0;
extern int has_GL_VERSION_2_1;
extern int has_GL_VERSION_3_0;
extern int has_GL_VERSION_3_1;
extern int has_GL_VERSION_3_2;
extern int has_GL_VERSION_3_3;
extern int has_GL_VERSION_4_0;
extern int has_GL_VERSION_4_1;
extern int has_GL_VERSION_4_2;
extern int has_GL_VERSION_4_3;
extern int has_GL_VERSION_4_4;
extern int has_GL_VERSION_4_5;
extern int has_GL_VERSION_4_6;
extern int has_GL_ARB_bindless_texture;
extern int has_GL_ARB_cl_event;
extern int has_GL_ARB_debug_output;
extern int has_GL_ARB_indirect_parameters;
extern int has_GL_ARB_shading_language_include;
extern int has_GL_ARB_texture_filter_minmax;
extern int has_GL_ARB_texture_float;
extern int has_GL_EXT_memory_object;
extern int has_GL_EXT_memory_object_fd;
extern int has_GL_EXT_memory_object_win32;
extern int has_GL_EXT_semaphore;
extern int has_GL_EXT_semaphore_fd;
extern int has_GL_EXT_semaphore_win32;
extern int has_GL_EXT_texture_compression_latc;
extern int has_GL_EXT_texture_compression_s3tc;
extern int has_GL_NV_bindless_texture;
extern int has_GL_NV_blend_equation_advanced;
extern int has_GL_NV_clip_space_w_scaling;
extern int has_GL_NV_command_list;
extern int has_GL_NV_compute_shader_derivatives;
extern int has_GL_NV_conservative_raster;
extern int has_GL_NV_conservative_raster_dilate;
extern int has_GL_NV_conservative_raster_pre_snap;
extern int has_GL_NV_conservative_raster_pre_snap_triangles;
extern int has_GL_NV_conservative_raster_underestimation;
extern int has_GL_NV_draw_vulkan_image;
extern int has_GL_NV_draw_texture;
extern int has_GL_NV_fill_rectangle;
extern int has_GL_NV_fragment_coverage_to_color;
extern int has_GL_NV_fragment_shader_barycentric;
extern int has_GL_NV_fragment_shader_interlock;
extern int has_GL_NV_framebuffer_mixed_samples;
extern int has_GL_NV_gpu_multicast;
extern int has_GL_NV_gpu_shader5;
extern int has_GL_NV_internalformat_sample_query;
extern int has_GL_NV_memory_attachment;
extern int has_GL_NV_mesh_shader;
extern int has_GL_NV_path_rendering;
extern int has_GL_NV_representative_fragment_test;
extern int has_GL_NV_sample_locations;
extern int has_GL_NV_sample_mask_override_coverage;
extern int has_GL_NV_scissor_exclusive;
extern int has_GL_NV_shader_atomic_int64;
extern int has_GL_NV_shader_buffer_load;
extern int has_GL_NV_shader_buffer_store;
extern int has_GL_NV_shader_texture_footprint;
extern int has_GL_NV_shader_thread_group;
extern int has_GL_NV_shader_thread_shuffle;
extern int has_GL_NV_shading_rate_image;
extern int has_GL_NV_stereo_view_rendering;
extern int has_GL_NV_texture_multisample;
extern int has_GL_NV_uniform_buffer_unified_memory;
extern int has_GL_NV_vertex_buffer_unified_memory;
extern int has_GL_NV_viewport_swizzle;
extern int has_GL_NVX_gpu_memory_info;
extern int has_GL_NV_query_resource;
extern int has_GL_NV_query_resource_tag;

/* loaders */
int load_GL_VERSION_1_1(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_VERSION_1_2(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_VERSION_1_3(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_VERSION_1_4(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_VERSION_1_5(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_VERSION_2_0(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_VERSION_2_1(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_VERSION_3_0(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_VERSION_3_1(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_VERSION_3_2(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_VERSION_3_3(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_VERSION_4_0(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_VERSION_4_1(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_VERSION_4_2(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_VERSION_4_3(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_VERSION_4_4(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_VERSION_4_5(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_VERSION_4_6(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_ARB_bindless_texture(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_ARB_cl_event(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_ARB_debug_output(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_ARB_indirect_parameters(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_ARB_shading_language_include(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_ARB_texture_filter_minmax(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_ARB_texture_float(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_EXT_memory_object(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_EXT_memory_object_fd(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_EXT_memory_object_win32(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_EXT_semaphore(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_EXT_semaphore_fd(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_EXT_semaphore_win32(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_EXT_texture_compression_latc(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_EXT_texture_compression_s3tc(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_NV_bindless_texture(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_NV_blend_equation_advanced(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_NV_clip_space_w_scaling(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_NV_command_list(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_NV_compute_shader_derivatives(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_NV_conservative_raster(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_NV_conservative_raster_dilate(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_NV_conservative_raster_pre_snap(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_NV_conservative_raster_pre_snap_triangles(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_NV_conservative_raster_underestimation(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_NV_draw_vulkan_image(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_NV_draw_texture(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_NV_fill_rectangle(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_NV_fragment_coverage_to_color(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_NV_fragment_shader_barycentric(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_NV_fragment_shader_interlock(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_NV_framebuffer_mixed_samples(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_NV_gpu_multicast(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_NV_gpu_shader5(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_NV_internalformat_sample_query(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_NV_memory_attachment(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_NV_mesh_shader(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_NV_path_rendering(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_NV_representative_fragment_test(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_NV_sample_locations(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_NV_sample_mask_override_coverage(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_NV_scissor_exclusive(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_NV_shader_atomic_int64(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_NV_shader_buffer_load(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_NV_shader_buffer_store(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_NV_shader_texture_footprint(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_NV_shader_thread_group(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_NV_shader_thread_shuffle(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_NV_shading_rate_image(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_NV_stereo_view_rendering(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_NV_texture_multisample(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_NV_uniform_buffer_unified_memory(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_NV_vertex_buffer_unified_memory(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_NV_viewport_swizzle(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_NVX_gpu_memory_info(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_NV_query_resource(nvGLLoaderGetProcFN fnGetProcAddress);
int load_GL_NV_query_resource_tag(nvGLLoaderGetProcFN fnGetProcAddress);

