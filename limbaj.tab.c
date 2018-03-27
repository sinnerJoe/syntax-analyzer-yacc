/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "limbaj.y" /* yacc.c:339  */

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include "state.h"
#include "print.h"
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
int yyerror(char *s)
{
    printf("Line:%i Error: \"%s\" \n", yylineno, s);
    anyErrors = 1;
}
int  yylex ();

#line 84 "limbaj.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "limbaj.tab.h".  */
#ifndef YY_YY_LIMBAJ_TAB_H_INCLUDED
# define YY_YY_LIMBAJ_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ID = 258,
    FOR = 259,
    WHILE = 260,
    DO = 261,
    FLOAT_L = 262,
    INT_L = 263,
    STRUCT = 264,
    ELSE = 265,
    EQ = 266,
    LTE = 267,
    GTE = 268,
    AND = 269,
    OR = 270,
    IF = 271,
    PRINT = 272,
    NEQ = 273,
    TIP_PRED = 274,
    BREAK = 275,
    CONTINUE = 276,
    RETURN = 277,
    CONST = 278,
    UMINUS = 279,
    PAR = 280
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 19 "limbaj.y" /* yacc.c:355  */

    struct variable* var;
    struct function* func;
    struct usr_type* tp;
    char* str;
    struct FormalParameter *fp;
    struct Declaration* decl;
    int ival;
    struct IncompleteVar* inc;
    struct Reference *ref;
    float fl;

#line 163 "limbaj.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_LIMBAJ_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 180 "limbaj.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  17
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   519

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  97
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  200

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   280

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    30,     2,     2,     2,    35,     2,     2,
      40,    41,    33,    31,    26,    32,    27,    34,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    24,
      29,    25,    28,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    42,     2,    43,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    38,     2,    39,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    36,
      37
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    62,    62,    68,    69,    72,    73,    76,    80,    83,
      88,    96,    97,   102,   103,   104,   110,   116,   124,   131,
     136,   140,   146,   147,   150,   154,   160,   163,   168,   174,
     182,   187,   193,   201,   204,   205,   211,   212,   215,   218,
     223,   224,   227,   230,   231,   234,   235,   241,   242,   244,
     245,   246,   247,   248,   249,   250,   251,   256,   257,   258,
     259,   262,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   306,   307
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "FOR", "WHILE", "DO", "FLOAT_L",
  "INT_L", "STRUCT", "ELSE", "EQ", "LTE", "GTE", "AND", "OR", "IF",
  "PRINT", "NEQ", "TIP_PRED", "BREAK", "CONTINUE", "RETURN", "CONST",
  "';'", "'='", "','", "'.'", "'>'", "'<'", "'!'", "'+'", "'-'", "'*'",
  "'/'", "'%'", "UMINUS", "PAR", "'{'", "'}'", "'('", "')'", "'['", "']'",
  "$accept", "progr", "declaratii", "decl_membri", "data_type",
  "decl_or_def", "declaratie", "declaratie_var", "declaratie_const",
  "const_indecl_elem", "const_indecl_elems", "indecl_elem", "indecl_elems",
  "formal_args", "definitie", "lista_param", "param", "bloc",
  "bloc_or_instr", "lista_instr", "apel_func", "lista_apel", "while_line",
  "reference", "nested_ref", "statement", "assignment", "EXPR", "CT_EXPR",
  "number", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,    59,    61,    44,    46,    62,    60,
      33,    43,    45,    42,    47,    37,   279,   280,   123,   125,
      40,    41,    91,    93
};
# endif

#define YYPACT_NINF -134

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-134)))

#define YYTABLE_NINF -8

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       5,   -24,     8,   -13,     3,    21,  -134,    20,     5,     7,
    -134,  -134,  -134,    24,    -3,    28,    60,  -134,   -10,    41,
    -134,  -134,  -134,    40,     3,    42,    59,    65,  -134,    86,
      66,    48,    96,  -134,    53,    96,    78,  -134,    86,    60,
     -33,  -134,  -134,    86,    86,    86,  -134,    77,  -134,   335,
    -134,  -134,   106,    70,    88,   197,  -134,    90,  -134,    95,
       3,   335,  -134,    80,    86,   121,  -134,   252,   124,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,  -134,  -134,     3,    61,   101,   102,    48,   107,   117,
     104,   105,   204,   134,   129,   136,   159,   145,  -134,   147,
     376,  -134,  -134,  -134,   131,   401,   227,  -134,   135,  -134,
     121,   121,   121,   390,   219,   121,   121,    62,    62,  -134,
    -134,  -134,  -134,     3,    86,   125,    86,   166,  -134,  -134,
    -134,   426,  -134,  -134,  -134,  -134,  -134,  -134,  -134,    86,
    -134,  -134,  -134,    86,  -134,   163,   263,   164,   288,   166,
     166,   166,   299,  -134,  -134,   335,  -134,    86,  -134,  -134,
     159,   151,  -134,   324,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   168,   451,   180,  -134,
     151,   151,   151,   484,   459,   151,   151,    89,    89,  -134,
    -134,  -134,  -134,   124,   159,   145,   152,  -134,   159,  -134
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     7,     0,     8,     0,     0,     2,     0,     3,     0,
      13,    14,    12,     0,    16,     0,     0,     1,    22,    24,
      17,     4,    11,     0,     0,     0,     0,    20,    18,     0,
       0,    15,     0,    10,     0,     0,     0,     9,     0,     0,
      43,    97,    96,     0,     0,     0,    71,    45,    62,    23,
      70,    26,     0,     0,    30,     0,    28,    22,    25,     0,
       5,    19,    21,     0,     0,    73,    75,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    32,    27,     0,    43,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    71,     0,    62,    36,     0,
       0,    29,     6,    39,     0,    40,     0,    72,    43,    46,
      67,    65,    66,    69,    68,    63,    64,    74,    76,    77,
      78,    79,    31,     0,     0,     0,     0,     0,    57,    58,
      59,     0,    48,    33,    37,    49,    35,    54,    34,     0,
      50,    47,    38,     0,    44,     0,     0,     0,     0,     0,
       0,     0,     0,    87,    60,    61,    41,     0,    42,    55,
       0,    89,    91,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    52,    88,
      84,    82,    83,    86,    85,    80,    81,    90,    92,    93,
      94,    95,    51,     0,     0,     0,     0,    53,     0,    56
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -134,  -134,   186,   148,    25,  -134,  -134,     2,  -134,  -134,
     156,  -134,   177,  -134,  -134,   127,  -134,   -27,  -133,  -134,
     -54,    72,    97,  -134,   -55,   -35,    27,   -26,   211,   -93
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,    34,    35,     8,     9,    93,    11,    27,
      28,    19,    20,    31,    12,    53,    54,   136,   137,    94,
      46,   104,    96,    47,    48,   138,    99,   100,   152,    50
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      97,    95,    10,    49,    56,    13,     1,    63,     1,    64,
      10,    14,    61,   109,     2,    29,    15,    65,    66,    67,
      98,    17,     3,    18,     3,     7,    36,   178,     4,    16,
      30,    22,    23,     7,   153,    24,    25,   105,   106,    97,
      95,    97,    95,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,    52,   153,   153,   153,   134,
     125,   197,    36,    26,    -7,   199,   131,    32,    33,     1,
      37,   153,   153,   153,   153,   153,   153,   153,   153,   153,
     153,   153,   153,    40,    38,     3,    55,    41,    42,    40,
      13,    39,    59,    41,    42,    78,    79,    80,   146,    57,
     148,    63,    60,    64,    68,    97,    95,    51,    52,    81,
      43,    82,    44,   155,    83,    29,    43,   105,    44,   101,
      45,   103,   173,   174,   175,   145,    45,   108,   128,   129,
      86,   177,    84,    85,    86,    87,    41,    42,   195,    97,
      95,   123,   124,    97,    95,    88,    89,   126,     3,    90,
      91,    92,    76,    77,    78,    79,    80,   127,   132,    43,
     135,    44,    84,    85,    86,    87,    41,    42,   133,    45,
     139,   140,   142,    41,    42,    88,    89,    64,     3,    90,
      91,    92,   171,   172,   173,   174,   175,   157,   159,    43,
     194,    44,   192,   198,    21,    62,   149,    55,   150,    45,
      84,    85,    86,    87,    41,    42,   151,    40,   102,    58,
     122,    41,    42,    88,    89,   156,     3,    90,    91,    92,
     196,     0,   147,     0,     0,     0,     0,    43,   130,    44,
      69,    70,    71,    72,    43,     0,    44,    45,    69,    70,
      71,    72,    73,     0,    45,     0,     0,    74,    75,     0,
      76,    77,    78,    79,    80,    74,    75,     0,    76,    77,
      78,    79,    80,    69,    70,    71,    72,    73,     0,     0,
     144,     0,     0,     0,    69,    70,    71,    72,    73,     0,
      74,    75,     0,    76,    77,    78,    79,    80,     0,     0,
       0,    74,    75,   107,    76,    77,    78,    79,    80,    69,
      70,    71,    72,    73,   158,     0,     0,     0,     0,     0,
     164,   165,   166,   167,   168,     0,    74,    75,     0,    76,
      77,    78,    79,    80,     0,     0,     0,   169,   170,   160,
     171,   172,   173,   174,   175,   164,   165,   166,   167,   168,
     176,     0,     0,     0,     0,     0,    69,    70,    71,    72,
      73,     0,   169,   170,     0,   171,   172,   173,   174,   175,
     161,   162,   163,    74,    75,   179,    76,    77,    78,    79,
      80,     0,     0,     0,     0,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    69,    70,    71,
      72,    73,     0,     0,     0,     0,     0,     0,     0,     0,
     141,    69,    70,    71,    74,    75,     0,    76,    77,    78,
      79,    80,    69,    70,    71,    72,    73,     0,    74,    75,
       0,    76,    77,    78,    79,    80,     0,   143,     0,    74,
      75,     0,    76,    77,    78,    79,    80,    69,    70,    71,
      72,    73,     0,     0,     0,     0,     0,     0,     0,     0,
     154,     0,     0,     0,    74,    75,     0,    76,    77,    78,
      79,    80,    69,    70,    71,    72,    73,     0,     0,     0,
     164,   165,   166,   167,     0,   193,     0,     0,     0,    74,
      75,     0,    76,    77,    78,    79,    80,   169,   170,     0,
     171,   172,   173,   174,   175,   164,   165,   166,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   169,   170,     0,   171,   172,   173,   174,   175
};

static const yytype_int16 yycheck[] =
{
      55,    55,     0,    29,    31,    29,     3,    40,     3,    42,
       8,     3,    38,    68,     9,    25,    29,    43,    44,    45,
      55,     0,    19,     3,    19,     0,    24,   160,    23,     4,
      40,    24,     8,     8,   127,    38,     8,    63,    64,    94,
      94,    96,    96,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    30,   149,   150,   151,    94,
      87,   194,    60,     3,     3,   198,    92,    26,    28,     3,
      28,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,     3,    25,    19,    38,     7,     8,     3,
      29,    26,    39,     7,     8,    33,    34,    35,   124,     3,
     126,    40,    24,    42,    27,   160,   160,    41,    83,     3,
      30,    41,    32,   139,    26,    25,    30,   143,    32,    24,
      40,    41,    33,    34,    35,   123,    40,     3,    24,    24,
       5,   157,     3,     4,     5,     6,     7,     8,   193,   194,
     194,    40,    40,   198,   198,    16,    17,    40,    19,    20,
      21,    22,    31,    32,    33,    34,    35,    40,    24,    30,
      24,    32,     3,     4,     5,     6,     7,     8,    39,    40,
      25,    24,    41,     7,     8,    16,    17,    42,    19,    20,
      21,    22,    31,    32,    33,    34,    35,    24,    24,    30,
      10,    32,    24,    41,     8,    39,    30,    38,    32,    40,
       3,     4,     5,     6,     7,     8,    40,     3,    60,    32,
      83,     7,     8,    16,    17,   143,    19,    20,    21,    22,
     193,    -1,   125,    -1,    -1,    -1,    -1,    30,    24,    32,
      11,    12,    13,    14,    30,    -1,    32,    40,    11,    12,
      13,    14,    15,    -1,    40,    -1,    -1,    28,    29,    -1,
      31,    32,    33,    34,    35,    28,    29,    -1,    31,    32,
      33,    34,    35,    11,    12,    13,    14,    15,    -1,    -1,
      43,    -1,    -1,    -1,    11,    12,    13,    14,    15,    -1,
      28,    29,    -1,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    28,    29,    41,    31,    32,    33,    34,    35,    11,
      12,    13,    14,    15,    41,    -1,    -1,    -1,    -1,    -1,
      11,    12,    13,    14,    15,    -1,    28,    29,    -1,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    28,    29,    41,
      31,    32,    33,    34,    35,    11,    12,    13,    14,    15,
      41,    -1,    -1,    -1,    -1,    -1,    11,    12,    13,    14,
      15,    -1,    28,    29,    -1,    31,    32,    33,    34,    35,
     149,   150,   151,    28,    29,    41,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    -1,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,    11,    12,    13,
      14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      24,    11,    12,    13,    28,    29,    -1,    31,    32,    33,
      34,    35,    11,    12,    13,    14,    15,    -1,    28,    29,
      -1,    31,    32,    33,    34,    35,    -1,    26,    -1,    28,
      29,    -1,    31,    32,    33,    34,    35,    11,    12,    13,
      14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      24,    -1,    -1,    -1,    28,    29,    -1,    31,    32,    33,
      34,    35,    11,    12,    13,    14,    15,    -1,    -1,    -1,
      11,    12,    13,    14,    -1,    24,    -1,    -1,    -1,    28,
      29,    -1,    31,    32,    33,    34,    35,    28,    29,    -1,
      31,    32,    33,    34,    35,    11,    12,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    29,    -1,    31,    32,    33,    34,    35
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     9,    19,    23,    45,    46,    48,    49,    50,
      51,    52,    58,    29,     3,    29,    48,     0,     3,    55,
      56,    46,    24,     8,    38,     8,     3,    53,    54,    25,
      40,    57,    26,    28,    47,    48,    51,    28,    25,    26,
       3,     7,     8,    30,    32,    40,    64,    67,    68,    71,
      73,    41,    48,    59,    60,    38,    61,     3,    56,    39,
      24,    71,    54,    40,    42,    71,    71,    71,    27,    11,
      12,    13,    14,    15,    28,    29,    31,    32,    33,    34,
      35,     3,    41,    26,     3,     4,     5,     6,    16,    17,
      20,    21,    22,    51,    63,    64,    66,    68,    69,    70,
      71,    24,    47,    41,    65,    71,    71,    41,     3,    68,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    59,    40,    40,    61,    40,    40,    24,    24,
      24,    71,    24,    39,    69,    24,    61,    62,    69,    25,
      24,    24,    41,    26,    43,    51,    71,    66,    71,    30,
      32,    40,    72,    73,    24,    71,    65,    24,    41,    24,
      41,    72,    72,    72,    11,    12,    13,    14,    15,    28,
      29,    31,    32,    33,    34,    35,    41,    71,    62,    41,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    24,    24,    10,    68,    70,    62,    41,    62
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    45,    46,    46,    47,    47,    48,    48,    48,
      48,    49,    49,    50,    50,    50,    50,    51,    52,    53,
      54,    54,    55,    55,    56,    56,    57,    57,    58,    58,
      59,    59,    60,    61,    62,    62,    63,    63,    64,    64,
      65,    65,    66,    67,    67,    68,    68,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    70,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    73,    73
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     3,     1,     1,     4,
       4,     2,     1,     1,     1,     3,     2,     2,     3,     3,
       1,     3,     1,     3,     1,     3,     2,     3,     4,     6,
       1,     3,     2,     3,     1,     1,     1,     2,     4,     3,
       1,     3,     4,     1,     4,     1,     3,     2,     2,     2,
       2,     5,     5,     7,     2,     4,     9,     2,     2,     2,
       3,     3,     1,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     3,     2,     3,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     3,     2,
       3,     2,     3,     3,     3,     3,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 7:
#line 76 "limbaj.y" /* yacc.c:1646  */
    {
             typeCheck((yyvsp[0].str));
             (yyval.tp)=newTypeStruct((yyvsp[0].str), 0);
            }
#line 1455 "limbaj.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 80 "limbaj.y" /* yacc.c:1646  */
    {
             (yyval.tp)=newTypeStruct((yyvsp[0].str), 0);
            }
#line 1463 "limbaj.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 83 "limbaj.y" /* yacc.c:1646  */
    {
             if(atoi((yyvsp[-1].str)) == 0) 
                yyerror("Cannot declare null-sized arrays");
             (yyval.tp)=newTypeStruct((yyvsp[-3].str), 1);
            }
#line 1473 "limbaj.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 88 "limbaj.y" /* yacc.c:1646  */
    {
             typeCheck((yyvsp[-3].str));
             if(atoi((yyvsp[-1].str)) == 0) 
                yyerror("Cannot declare null-sized arrays");
             (yyval.tp)=newTypeStruct((yyvsp[-3].str), 1);
            }
#line 1484 "limbaj.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 102 "limbaj.y" /* yacc.c:1646  */
    { executeDeclGlobal((yyvsp[0].decl)); }
#line 1490 "limbaj.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 103 "limbaj.y" /* yacc.c:1646  */
    { executeDeclGlobal((yyvsp[0].decl));  }
#line 1496 "limbaj.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 104 "limbaj.y" /* yacc.c:1646  */
    {
              struct function* f = (yyvsp[0].func);
              f->name = (yyvsp[-1].str);
              f->funcType = (yyvsp[-2].tp);
              declareFunction(f);
            }
#line 1507 "limbaj.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 110 "limbaj.y" /* yacc.c:1646  */
    {
              declareUsrType((yyvsp[0].str));
            }
#line 1515 "limbaj.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 117 "limbaj.y" /* yacc.c:1646  */
    {   //$$-Declaratie
                    (yyvsp[0].decl)->type = (yyvsp[-1].tp);
                    (yyvsp[0].decl)->type->isConst = 0;
                    (yyval.decl)=(yyvsp[0].decl);
                }
#line 1525 "limbaj.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 124 "limbaj.y" /* yacc.c:1646  */
    { //$$-declaratie
                    (yyvsp[0].decl)->type = (yyvsp[-1].tp);
                    (yyvsp[0].decl)->type->isConst = 1;
                    (yyval.decl)=(yyvsp[0].decl);
}
#line 1535 "limbaj.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 131 "limbaj.y" /* yacc.c:1646  */
    {
                    (yyval.str)=(yyvsp[-2].str);
                 }
#line 1543 "limbaj.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 136 "limbaj.y" /* yacc.c:1646  */
    {
                        (yyval.decl) = calloc(1, sizeof(Declaration));
                        addDeclVar((yyvsp[0].str), (bool)1, (yyval.decl));
                    }
#line 1552 "limbaj.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 140 "limbaj.y" /* yacc.c:1646  */
    {
                        (yyval.decl)=(yyvsp[0].decl);
                        addDeclVar((yyvsp[-2].str), (bool)1, (yyval.decl));
                  }
#line 1561 "limbaj.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 146 "limbaj.y" /* yacc.c:1646  */
    { (yyval.inc)=newIncompleteVar((yyvsp[0].str), 0); /*inc*/ }
#line 1567 "limbaj.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 147 "limbaj.y" /* yacc.c:1646  */
    {  (yyval.inc)=newIncompleteVar((yyvsp[-2].str), 1); }
#line 1573 "limbaj.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 150 "limbaj.y" /* yacc.c:1646  */
    { //$$-declaration
                (yyval.decl) = calloc(1, sizeof(Declaration));
                addDeclVar((yyvsp[0].inc)->name, (bool)(yyvsp[0].inc)->initialized, (yyval.decl));
            }
#line 1582 "limbaj.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 154 "limbaj.y" /* yacc.c:1646  */
    {
                addDeclVar((yyvsp[-2].inc)->name, (bool)(yyvsp[-2].inc)->initialized, (yyvsp[0].decl));
                (yyval.decl)=(yyvsp[0].decl);
            }
#line 1591 "limbaj.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 160 "limbaj.y" /* yacc.c:1646  */
    {
                (yyval.func) = newFunc();
            }
#line 1599 "limbaj.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 163 "limbaj.y" /* yacc.c:1646  */
    {
               (yyval.func) = (yyvsp[-1].func);
           }
#line 1607 "limbaj.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 168 "limbaj.y" /* yacc.c:1646  */
    {
                struct function* f = (yyvsp[-1].func);
                f->name = (yyvsp[-2].str);
                f->funcType = (yyvsp[-3].tp);
                defineFunction(f);
                }
#line 1618 "limbaj.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 174 "limbaj.y" /* yacc.c:1646  */
    {
             defineUsrType((yyvsp[-4].str));
         }
#line 1626 "limbaj.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 182 "limbaj.y" /* yacc.c:1646  */
    { //function
                struct function * func =  newFunc();
                addParam((yyvsp[0].fp), func);
                (yyval.func)=func;
            }
#line 1636 "limbaj.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 187 "limbaj.y" /* yacc.c:1646  */
    {
               addParam((yyvsp[-2].fp), (yyvsp[0].func));
               (yyval.func)=(yyvsp[0].func);
           }
#line 1645 "limbaj.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 193 "limbaj.y" /* yacc.c:1646  */
    { // FormalParameter
        (yyval.fp) = calloc(1, sizeof(FormalParameter));
        (yyval.fp)->name = (yyvsp[0].str);
        (yyval.fp)->tp = (yyvsp[-1].tp);
     }
#line 1655 "limbaj.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 215 "limbaj.y" /* yacc.c:1646  */
    {
                callFunction((yyvsp[-3].str), (yyvsp[-1].ival));
            }
#line 1663 "limbaj.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 218 "limbaj.y" /* yacc.c:1646  */
    { 
             callFunction((yyvsp[-2].str), 0);
         }
#line 1671 "limbaj.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 223 "limbaj.y" /* yacc.c:1646  */
    {(yyval.ival)=1;}
#line 1677 "limbaj.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 224 "limbaj.y" /* yacc.c:1646  */
    {(yyval.ival)=(yyvsp[0].ival)+1;}
#line 1683 "limbaj.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 230 "limbaj.y" /* yacc.c:1646  */
    { (yyval.ref) = malloc(sizeof(struct Reference)); (yyval.ref)->name = (yyvsp[0].str);  (yyval.ref)->indexed = 0; }
#line 1689 "limbaj.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 231 "limbaj.y" /* yacc.c:1646  */
    { (yyval.ref) = malloc(sizeof(struct Reference)); (yyval.ref)->name = (yyvsp[-3].str);  (yyval.ref)->indexed = 1;}
#line 1695 "limbaj.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 234 "limbaj.y" /* yacc.c:1646  */
    { (yyval.ref) = (yyvsp[0].ref); }
#line 1701 "limbaj.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 235 "limbaj.y" /* yacc.c:1646  */
    {
            (yyval.ref)=(yyvsp[-2].ref);
          }
#line 1709 "limbaj.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 242 "limbaj.y" /* yacc.c:1646  */
    { 
             executeDeclLocal((yyvsp[-1].decl));                }
#line 1716 "limbaj.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 245 "limbaj.y" /* yacc.c:1646  */
    { assign((yyvsp[-1].ref)->name, (yyvsp[-1].ref)->indexed); }
#line 1722 "limbaj.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 246 "limbaj.y" /* yacc.c:1646  */
    { addToPrintQueue((yyvsp[-2].fl)); }
#line 1728 "limbaj.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 252 "limbaj.y" /* yacc.c:1646  */
    {
                    executeDeclLocal((yyvsp[-6].decl));
                    assign((yyvsp[-2].ref)->name, (yyvsp[-2].ref)->indexed);
                }
#line 1737 "limbaj.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 262 "limbaj.y" /* yacc.c:1646  */
    {
                (yyval.ref)=(yyvsp[-2].ref);
            }
#line 1745 "limbaj.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 268 "limbaj.y" /* yacc.c:1646  */
    { rvalDeref((yyvsp[0].ref));}
#line 1751 "limbaj.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 288 "limbaj.y" /* yacc.c:1646  */
    {(yyval.fl) =  (yyvsp[-2].fl) > (yyvsp[0].fl);}
#line 1757 "limbaj.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 289 "limbaj.y" /* yacc.c:1646  */
    {(yyval.fl) = (yyvsp[-2].fl) < (yyvsp[0].fl); }
#line 1763 "limbaj.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 290 "limbaj.y" /* yacc.c:1646  */
    {(yyval.fl) = (yyvsp[-2].fl) <= (yyvsp[0].fl); }
#line 1769 "limbaj.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 291 "limbaj.y" /* yacc.c:1646  */
    {(yyval.fl) = (yyvsp[-2].fl) >= (yyvsp[0].fl); }
#line 1775 "limbaj.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 292 "limbaj.y" /* yacc.c:1646  */
    {(yyval.fl) = (yyvsp[-2].fl) == (yyvsp[0].fl); }
#line 1781 "limbaj.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 293 "limbaj.y" /* yacc.c:1646  */
    {(yyval.fl) = ((yyvsp[-2].fl)!=0) || ((yyvsp[0].fl)!=0); }
#line 1787 "limbaj.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 294 "limbaj.y" /* yacc.c:1646  */
    {(yyval.fl) = ((yyvsp[-2].fl)!=0) && ((yyvsp[0].fl)!=0); }
#line 1793 "limbaj.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 295 "limbaj.y" /* yacc.c:1646  */
    {(yyval.fl) = (yyvsp[0].fl);}
#line 1799 "limbaj.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 296 "limbaj.y" /* yacc.c:1646  */
    {(yyval.fl) = (yyvsp[-1].fl);}
#line 1805 "limbaj.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 297 "limbaj.y" /* yacc.c:1646  */
    {(yyval.fl) = (yyvsp[0].fl)==0;}
#line 1811 "limbaj.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 298 "limbaj.y" /* yacc.c:1646  */
    {(yyval.fl) = (yyvsp[-2].fl) + (yyvsp[0].fl);}
#line 1817 "limbaj.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 299 "limbaj.y" /* yacc.c:1646  */
    {(yyval.fl) = -(yyvsp[0].fl);}
#line 1823 "limbaj.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 300 "limbaj.y" /* yacc.c:1646  */
    {(yyval.fl) = (yyvsp[-2].fl) - (yyvsp[0].fl);}
#line 1829 "limbaj.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 301 "limbaj.y" /* yacc.c:1646  */
    {(yyval.fl) = (yyvsp[-2].fl) * (yyvsp[0].fl);}
#line 1835 "limbaj.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 302 "limbaj.y" /* yacc.c:1646  */
    {(yyval.fl) = (yyvsp[-2].fl) / (yyvsp[0].fl);}
#line 1841 "limbaj.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 303 "limbaj.y" /* yacc.c:1646  */
    {(yyval.fl) = (int)(yyvsp[-2].fl) % (int)(yyvsp[0].fl);}
#line 1847 "limbaj.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 306 "limbaj.y" /* yacc.c:1646  */
    {(yyval.fl) = atoi((yyvsp[0].str));}
#line 1853 "limbaj.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 307 "limbaj.y" /* yacc.c:1646  */
    {(yyval.fl) = atof((yyvsp[0].str));}
#line 1859 "limbaj.tab.c" /* yacc.c:1646  */
    break;


#line 1863 "limbaj.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 311 "limbaj.y" /* yacc.c:1906  */



int main(int argc, char** argv){
yyin=fopen(argv[1],"r");
yyparse();
checkUndefinedFunctions();
checkUndefinedTypes();
if(!anyErrors){
    printEverything();
}
} 
