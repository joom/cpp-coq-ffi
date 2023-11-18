#ifndef PROG_PROG_C
#define PROG_PROG_C
#include "gc_stack.h"
#include "/home/coq/.opam/4.13.1+flambda/.opam-switch/build/coq-certicoq.dev+8.17/plugin/runtime/prim_floats.h"
#include "/home/coq/.opam/4.13.1+flambda/.opam-switch/build/coq-certicoq.dev+8.17/plugin/runtime/prim_int63.h"
#include "/home/coq/.opam/4.13.1+flambda/.opam-switch/build/coq-certicoq.dev+8.17/plugin/runtime/coq_c_ffi.h"
#include "prims.h"
#include "prog.prog.h"
extern struct thread_info *make_tinfo(void);
extern value y_wrapper_111(struct thread_info *, value, value);
extern value y_wrapper_110(struct thread_info *, value, value);
extern value y_wrapper_109(struct thread_info *, value, value);
extern value y_wrapper_108(struct thread_info *, value, value);
extern value y_wrapper_107(struct thread_info *, value, value);
extern value y_known_106(struct thread_info *, value, value);
extern value y_known_105(struct thread_info *, value, value);
extern value y_known_104(struct thread_info *, value, value);
extern value prim_wrapper_wrapper_103(struct thread_info *, value, value);
extern value body(struct thread_info *);
value y_wrapper_111(struct thread_info *, value, value);
value y_wrapper_110(struct thread_info *, value, value);
value y_wrapper_109(struct thread_info *, value, value);
value y_wrapper_108(struct thread_info *, value, value);
value y_wrapper_107(struct thread_info *, value, value);
value y_known_106(struct thread_info *, value, value);
value y_known_105(struct thread_info *, value, value);
value y_known_104(struct thread_info *, value, value);
value prim_wrapper_wrapper_103(struct thread_info *, value, value);
value body(struct thread_info *);
unsigned long long const body_info_203[2] = { 10LL, 0LL, };

unsigned long long const prim_wrapper_wrapper_info_202[4] = { 0LL, 2LL, 0LL,
  1LL, };

unsigned long long const y_known_info_201[4] = { 18LL, 2LL, 0LL, 1LL, };

unsigned long long const y_known_info_200[4] = { 20LL, 2LL, 0LL, 1LL, };

unsigned long long const y_known_info_199[4] = { 22LL, 2LL, 0LL, 1LL, };

unsigned long long const y_wrapper_info_198[4] = { 5LL, 2LL, 0LL, 1LL, };

unsigned long long const y_wrapper_info_197[4] = { 0LL, 2LL, 0LL, 1LL, };

unsigned long long const y_wrapper_info_196[4] = { 0LL, 2LL, 0LL, 1LL, };

unsigned long long const y_wrapper_info_195[4] = { 0LL, 2LL, 0LL, 1LL, };

unsigned long long const y_wrapper_info_194[4] = { 13LL, 2LL, 0LL, 1LL, };

value y_wrapper_111(struct thread_info *$tinfo, value $env_177, value $s_178)
{
  struct stack_frame frame;
  value root[1];
  register value $progdHashable_nat_proj_179;
  register value $y_180;
  register value $y_181;
  register value $env_182;
  register value $y_183;
  register value $y_184;
  register value $y_wrapper_clo_185;
  register value $y_186;
  register value *$alloc;
  register value *$limit;
  register value *$args;
  register _Bool $arg;
  register value $result;
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  $args = (*$tinfo).args;
  frame.next = root;
  frame.root = root;
  frame.prev = (*$tinfo).fp;
  if (!(13LL <= $limit - $alloc)) {
    *(root + 0LL) = $env_177;
    frame.next = root + 1LL;
    (*$tinfo).fp = &frame;
    (*$tinfo).nalloc = 13LL;
    garbage_collect($tinfo);
    $env_177 = *(root + 0LL);
    (*$tinfo).fp = frame.prev;
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $progdHashable_nat_proj_179 = *((value *) $env_177 + 0LL);
  $y_180 = 1LL;
  $y_181 = (value) ($alloc + 1LL);
  $alloc = $alloc + 3LL;
  *((value *) $y_181 + -1LL) = 2050LL;
  *((value *) $y_181 + 0LL) = $y_180;
  *((value *) $y_181 + 1LL) = $progdHashable_nat_proj_179;
  $env_182 = (value) ($alloc + 1LL);
  $alloc = $alloc + 2LL;
  *((value *) $env_182 + -1LL) = 1024LL;
  *((value *) $env_182 + 0LL) = $progdHashable_nat_proj_179;
  $y_183 = 1LL;
  $y_184 = 1LL;
  $y_wrapper_clo_185 = (value) ($alloc + 1LL);
  $alloc = $alloc + 3LL;
  *((value *) $y_wrapper_clo_185 + -1LL) = 2048LL;
  *((value *) $y_wrapper_clo_185 + 0LL) = y_wrapper_110;
  *((value *) $y_wrapper_clo_185 + 1LL) = $env_182;
  $y_186 = (value) ($alloc + 1LL);
  $alloc = $alloc + 5LL;
  *((value *) $y_186 + -1LL) = 4097LL;
  *((value *) $y_186 + 0LL) = $y_183;
  *((value *) $y_186 + 1LL) = $y_184;
  *((value *) $y_186 + 2LL) = $y_181;
  *((value *) $y_186 + 3LL) = $y_wrapper_clo_185;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $y_186;
}

value y_wrapper_110(struct thread_info *$tinfo, value $env_173, value $s_174)
{
  struct stack_frame frame;
  value root[2];
  register value $progdHashable_nat_proj_176;
  register value *$alloc;
  register value *$limit;
  register value *$args;
  register _Bool $arg;
  register value $result;
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  $args = (*$tinfo).args;
  frame.next = root;
  frame.root = root;
  frame.prev = (*$tinfo).fp;
  $progdHashable_nat_proj_176 = *((value *) $env_173 + 0LL);
  $args = (*$tinfo).args;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  $result =
    ((value (*)(struct thread_info *, value, value)) y_known_104)
    ($tinfo, $s_174, $progdHashable_nat_proj_176);
  return $result;
}

value y_wrapper_109(struct thread_info *$tinfo, value $env_168, value $anon_169)
{
  struct stack_frame frame;
  value root[1];
  register value $progdHashable_nat_proj_171;
  register value $s_proj_172;
  register value *$alloc;
  register value *$limit;
  register value *$args;
  register _Bool $arg;
  register value $result;
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  $args = (*$tinfo).args;
  frame.next = root;
  frame.root = root;
  frame.prev = (*$tinfo).fp;
  $progdHashable_nat_proj_171 = *((value *) $env_168 + 1LL);
  $s_proj_172 = *((value *) $env_168 + 0LL);
  $args = (*$tinfo).args;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  $result =
    ((value (*)(struct thread_info *, value, value)) y_known_105)
    ($tinfo, $progdHashable_nat_proj_171, $s_proj_172);
  return $result;
}

value y_wrapper_108(struct thread_info *$tinfo, value $env_163, value $anon_164)
{
  struct stack_frame frame;
  value root[1];
  register value $progdHashable_nat_proj_166;
  register value $s_proj_167;
  register value *$alloc;
  register value *$limit;
  register value *$args;
  register _Bool $arg;
  register value $result;
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  $args = (*$tinfo).args;
  frame.next = root;
  frame.root = root;
  frame.prev = (*$tinfo).fp;
  $progdHashable_nat_proj_166 = *((value *) $env_163 + 1LL);
  $s_proj_167 = *((value *) $env_163 + 0LL);
  $args = (*$tinfo).args;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  $result =
    ((value (*)(struct thread_info *, value, value)) y_known_106)
    ($tinfo, $progdHashable_nat_proj_166, $s_proj_167);
  return $result;
}

value y_wrapper_107(struct thread_info *$tinfo, value $env_156, value $anon_157)
{
  struct stack_frame frame;
  value root[1];
  register value $progdHashable_nat_proj_158;
  register value $s_proj_159;
  register value $y_160;
  register value $y_161;
  register value $y_162;
  register value *$alloc;
  register value *$limit;
  register value *$args;
  register _Bool $arg;
  register value $result;
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  $args = (*$tinfo).args;
  frame.next = root;
  frame.root = root;
  frame.prev = (*$tinfo).fp;
  if (!(5LL <= $limit - $alloc)) {
    *(root + 0LL) = $env_156;
    frame.next = root + 1LL;
    (*$tinfo).fp = &frame;
    (*$tinfo).nalloc = 5LL;
    garbage_collect($tinfo);
    $env_156 = *(root + 0LL);
    (*$tinfo).fp = frame.prev;
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $progdHashable_nat_proj_158 = *((value *) $env_156 + 1LL);
  $s_proj_159 = *((value *) $env_156 + 0LL);
  $y_160 = 1LL;
  $y_161 = 1LL;
  $y_162 = (value) ($alloc + 1LL);
  $alloc = $alloc + 5LL;
  *((value *) $y_162 + -1LL) = 4099LL;
  *((value *) $y_162 + 0LL) = $y_161;
  *((value *) $y_162 + 1LL) = $progdHashable_nat_proj_158;
  *((value *) $y_162 + 2LL) = $s_proj_159;
  *((value *) $y_162 + 3LL) = $y_160;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $y_162;
}

value y_known_106(struct thread_info *$tinfo, value $progdHashable_nat_143, value $s_144)
{
  struct stack_frame frame;
  value root[2];
  register value $y_145;
  register value $y_146;
  register value $y_147;
  register value $y_148;
  register value $y_149;
  register value $y_150;
  register value $env_151;
  register value $y_152;
  register value $y_153;
  register value $y_wrapper_clo_154;
  register value $y_155;
  register value *$alloc;
  register value *$limit;
  register value *$args;
  register _Bool $arg;
  register value $result;
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  $args = (*$tinfo).args;
  frame.next = root;
  frame.root = root;
  frame.prev = (*$tinfo).fp;
  if (!(22LL <= $limit - $alloc)) {
    *(root + 1LL) = $s_144;
    *(root + 0LL) = $progdHashable_nat_143;
    frame.next = root + 2LL;
    (*$tinfo).fp = &frame;
    (*$tinfo).nalloc = 22LL;
    garbage_collect($tinfo);
    $s_144 = *(root + 1LL);
    $progdHashable_nat_143 = *(root + 0LL);
    (*$tinfo).fp = frame.prev;
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $y_145 = 1LL;
  $y_146 = (value) ($alloc + 1LL);
  $alloc = $alloc + 2LL;
  *((value *) $y_146 + -1LL) = 1024LL;
  *((value *) $y_146 + 0LL) = $y_145;
  $y_147 = (value) ($alloc + 1LL);
  $alloc = $alloc + 2LL;
  *((value *) $y_147 + -1LL) = 1024LL;
  *((value *) $y_147 + 0LL) = $y_146;
  $y_148 = (value) ($alloc + 1LL);
  $alloc = $alloc + 2LL;
  *((value *) $y_148 + -1LL) = 1024LL;
  *((value *) $y_148 + 0LL) = $y_147;
  $y_149 = 1LL;
  $y_150 = (value) ($alloc + 1LL);
  $alloc = $alloc + 5LL;
  *((value *) $y_150 + -1LL) = 4100LL;
  *((value *) $y_150 + 0LL) = $y_149;
  *((value *) $y_150 + 1LL) = $progdHashable_nat_143;
  *((value *) $y_150 + 2LL) = $s_144;
  *((value *) $y_150 + 3LL) = $y_148;
  $env_151 = (value) ($alloc + 1LL);
  $alloc = $alloc + 3LL;
  *((value *) $env_151 + -1LL) = 2048LL;
  *((value *) $env_151 + 0LL) = $s_144;
  *((value *) $env_151 + 1LL) = $progdHashable_nat_143;
  $y_152 = 1LL;
  $y_153 = 1LL;
  $y_wrapper_clo_154 = (value) ($alloc + 1LL);
  $alloc = $alloc + 3LL;
  *((value *) $y_wrapper_clo_154 + -1LL) = 2048LL;
  *((value *) $y_wrapper_clo_154 + 0LL) = y_wrapper_107;
  *((value *) $y_wrapper_clo_154 + 1LL) = $env_151;
  $y_155 = (value) ($alloc + 1LL);
  $alloc = $alloc + 5LL;
  *((value *) $y_155 + -1LL) = 4097LL;
  *((value *) $y_155 + 0LL) = $y_152;
  *((value *) $y_155 + 1LL) = $y_153;
  *((value *) $y_155 + 2LL) = $y_150;
  *((value *) $y_155 + 3LL) = $y_wrapper_clo_154;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $y_155;
}

value y_known_105(struct thread_info *$tinfo, value $progdHashable_nat_129, value $s_130)
{
  struct stack_frame frame;
  value root[2];
  register value $y_131;
  register value $y_132;
  register value $y_133;
  register value $y_134;
  register value $y_135;
  register value $env_136;
  register value $y_137;
  register value $y_138;
  register value $y_wrapper_clo_139;
  register value $y_140;
  register value *$alloc;
  register value *$limit;
  register value *$args;
  register _Bool $arg;
  register value $result;
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  $args = (*$tinfo).args;
  frame.next = root;
  frame.root = root;
  frame.prev = (*$tinfo).fp;
  if (!(20LL <= $limit - $alloc)) {
    *(root + 1LL) = $s_130;
    *(root + 0LL) = $progdHashable_nat_129;
    frame.next = root + 2LL;
    (*$tinfo).fp = &frame;
    (*$tinfo).nalloc = 20LL;
    garbage_collect($tinfo);
    $s_130 = *(root + 1LL);
    $progdHashable_nat_129 = *(root + 0LL);
    (*$tinfo).fp = frame.prev;
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $y_131 = 1LL;
  $y_132 = (value) ($alloc + 1LL);
  $alloc = $alloc + 2LL;
  *((value *) $y_132 + -1LL) = 1024LL;
  *((value *) $y_132 + 0LL) = $y_131;
  $y_133 = (value) ($alloc + 1LL);
  $alloc = $alloc + 2LL;
  *((value *) $y_133 + -1LL) = 1024LL;
  *((value *) $y_133 + 0LL) = $y_132;
  $y_134 = 1LL;
  $y_135 = (value) ($alloc + 1LL);
  $alloc = $alloc + 5LL;
  *((value *) $y_135 + -1LL) = 4100LL;
  *((value *) $y_135 + 0LL) = $y_134;
  *((value *) $y_135 + 1LL) = $progdHashable_nat_129;
  *((value *) $y_135 + 2LL) = $s_130;
  *((value *) $y_135 + 3LL) = $y_133;
  $env_136 = (value) ($alloc + 1LL);
  $alloc = $alloc + 3LL;
  *((value *) $env_136 + -1LL) = 2048LL;
  *((value *) $env_136 + 0LL) = $s_130;
  *((value *) $env_136 + 1LL) = $progdHashable_nat_129;
  $y_137 = 1LL;
  $y_138 = 1LL;
  $y_wrapper_clo_139 = (value) ($alloc + 1LL);
  $alloc = $alloc + 3LL;
  *((value *) $y_wrapper_clo_139 + -1LL) = 2048LL;
  *((value *) $y_wrapper_clo_139 + 0LL) = y_wrapper_108;
  *((value *) $y_wrapper_clo_139 + 1LL) = $env_136;
  $y_140 = (value) ($alloc + 1LL);
  $alloc = $alloc + 5LL;
  *((value *) $y_140 + -1LL) = 4097LL;
  *((value *) $y_140 + 0LL) = $y_137;
  *((value *) $y_140 + 1LL) = $y_138;
  *((value *) $y_140 + 2LL) = $y_135;
  *((value *) $y_140 + 3LL) = $y_wrapper_clo_139;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $y_140;
}

value y_known_104(struct thread_info *$tinfo, value $s_116, value $progdHashable_nat_117)
{
  struct stack_frame frame;
  value root[2];
  register value $y_118;
  register value $y_119;
  register value $y_120;
  register value $y_121;
  register value $env_122;
  register value $y_123;
  register value $y_124;
  register value $y_wrapper_clo_125;
  register value $y_126;
  register value *$alloc;
  register value *$limit;
  register value *$args;
  register _Bool $arg;
  register value $result;
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  $args = (*$tinfo).args;
  frame.next = root;
  frame.root = root;
  frame.prev = (*$tinfo).fp;
  if (!(18LL <= $limit - $alloc)) {
    *(root + 1LL) = $progdHashable_nat_117;
    *(root + 0LL) = $s_116;
    frame.next = root + 2LL;
    (*$tinfo).fp = &frame;
    (*$tinfo).nalloc = 18LL;
    garbage_collect($tinfo);
    $progdHashable_nat_117 = *(root + 1LL);
    $s_116 = *(root + 0LL);
    (*$tinfo).fp = frame.prev;
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $y_118 = 1LL;
  $y_119 = (value) ($alloc + 1LL);
  $alloc = $alloc + 2LL;
  *((value *) $y_119 + -1LL) = 1024LL;
  *((value *) $y_119 + 0LL) = $y_118;
  $y_120 = 1LL;
  $y_121 = (value) ($alloc + 1LL);
  $alloc = $alloc + 5LL;
  *((value *) $y_121 + -1LL) = 4100LL;
  *((value *) $y_121 + 0LL) = $y_120;
  *((value *) $y_121 + 1LL) = $progdHashable_nat_117;
  *((value *) $y_121 + 2LL) = $s_116;
  *((value *) $y_121 + 3LL) = $y_119;
  $env_122 = (value) ($alloc + 1LL);
  $alloc = $alloc + 3LL;
  *((value *) $env_122 + -1LL) = 2048LL;
  *((value *) $env_122 + 0LL) = $s_116;
  *((value *) $env_122 + 1LL) = $progdHashable_nat_117;
  $y_123 = 1LL;
  $y_124 = 1LL;
  $y_wrapper_clo_125 = (value) ($alloc + 1LL);
  $alloc = $alloc + 3LL;
  *((value *) $y_wrapper_clo_125 + -1LL) = 2048LL;
  *((value *) $y_wrapper_clo_125 + 0LL) = y_wrapper_109;
  *((value *) $y_wrapper_clo_125 + 1LL) = $env_122;
  $y_126 = (value) ($alloc + 1LL);
  $alloc = $alloc + 5LL;
  *((value *) $y_126 + -1LL) = 4097LL;
  *((value *) $y_126 + 0LL) = $y_123;
  *((value *) $y_126 + 1LL) = $y_124;
  *((value *) $y_126 + 2LL) = $y_121;
  *((value *) $y_126 + 3LL) = $y_wrapper_clo_125;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $y_126;
}

value prim_wrapper_wrapper_103(struct thread_info *$tinfo, value $env_112, value $p_arg_113)
{
  struct stack_frame frame;
  value root[1];
  register value $prim_114;
  register value *$alloc;
  register value *$limit;
  register value *$args;
  register _Bool $arg;
  register value $result;
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  $args = (*$tinfo).args;
  frame.next = root;
  frame.root = root;
  frame.prev = (*$tinfo).fp;
  $prim_114 = ((value (*)(value)) uint63_from_nat)($p_arg_113);
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $prim_114;
}

value body(struct thread_info *$tinfo)
{
  struct stack_frame frame;
  value root[0];
  register value $env_187;
  register value $prim_wrapper_wrapper_clo_188;
  register value $progdHashable_nat_189;
  register value $y_190;
  register value $env_191;
  register value $y_wrapper_clo_192;
  register value $prim_193;
  register value *$alloc;
  register value *$limit;
  register value *$args;
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  $args = (*$tinfo).args;
  frame.next = root;
  frame.root = root;
  frame.prev = (*$tinfo).fp;
  if (!(10LL <= $limit - $alloc)) {
    /*skip*/;
    (*$tinfo).nalloc = 10LL;
    garbage_collect($tinfo);
    /*skip*/;
    $alloc = (*$tinfo).alloc;
    $limit = (*$tinfo).limit;
  }
  $env_187 = 1LL;
  $prim_wrapper_wrapper_clo_188 = (value) ($alloc + 1LL);
  $alloc = $alloc + 3LL;
  *((value *) $prim_wrapper_wrapper_clo_188 + -1LL) = 2048LL;
  *((value *) $prim_wrapper_wrapper_clo_188 + 0LL) =
    prim_wrapper_wrapper_103;
  *((value *) $prim_wrapper_wrapper_clo_188 + 1LL) = $env_187;
  $progdHashable_nat_189 = (value) ($alloc + 1LL);
  $alloc = $alloc + 2LL;
  *((value *) $progdHashable_nat_189 + -1LL) = 1024LL;
  *((value *) $progdHashable_nat_189 + 0LL) = $prim_wrapper_wrapper_clo_188;
  $y_190 = 1LL;
  $env_191 = (value) ($alloc + 1LL);
  $alloc = $alloc + 2LL;
  *((value *) $env_191 + -1LL) = 1024LL;
  *((value *) $env_191 + 0LL) = $progdHashable_nat_189;
  $y_wrapper_clo_192 = (value) ($alloc + 1LL);
  $alloc = $alloc + 3LL;
  *((value *) $y_wrapper_clo_192 + -1LL) = 2048LL;
  *((value *) $y_wrapper_clo_192 + 0LL) = y_wrapper_111;
  *((value *) $y_wrapper_clo_192 + 1LL) = $env_191;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  /*skip*/;
  $prim_193 =
    ((value (*)(struct thread_info *, value, value)) set_runM)
    ($tinfo, $y_190, $y_wrapper_clo_192);
  $alloc = (*$tinfo).alloc;
  $limit = (*$tinfo).limit;
  /*skip*/;
  (*$tinfo).alloc = $alloc;
  (*$tinfo).limit = $limit;
  return $prim_193;
}


#endif /* PROG_PROG_C */
