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
#line 1 "parser.y" /* yacc.c:339  */

   #include "class-defs.h"
   #include <bits/stdc++.h>
   extern "C" int yylex();
   extern "C" int yyparse();
   extern "C" FILE *yyin;
   extern "C" int line_num;
   extern union Node yylval;
   extern "C" int errors;
   void yyerror (char const *s);
   class Prog* start = NULL;

#line 79 "parser.tab.c" /* yacc.c:339  */

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
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    STRING = 258,
    NUMBER = 259,
    FOR = 260,
    WHILE = 261,
    IF = 262,
    ELSE = 263,
    GOTO = 264,
    declblock = 265,
    codeblock = 266,
    IDENTIFIER = 267,
    ETOK = 268,
    SENTENCE = 269,
    INT = 270,
    COUT = 271,
    OO = 272,
    AA = 273,
    ADDEQ = 274,
    SUBEQ = 275,
    NE = 276,
    EE = 277,
    LE = 278,
    GE = 279,
    LS = 280,
    RS = 281
  };
#endif

/* Value type.  */


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 152 "parser.tab.c" /* yacc.c:358  */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   353

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  149

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   281

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    38,    28,     2,     2,    36,    25,     2,
      21,    22,    34,    31,    29,    30,     2,    35,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    26,    48,
      40,    39,    41,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    17,     2,    18,    37,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    20,    27,    19,     2,     2,     2,     2,
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
      15,    16,    23,    24,    32,    33,    42,    43,    44,    45,
      46,    47
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    83,    83,    90,    91,    93,    93,    95,    95,    97,
      98,   106,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   119,   120,   122,   123,   124,   127,   128,   132,   133,
     134,   135,   136,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   157,   159,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   174,
     176,   177,   180,   181
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "STRING", "NUMBER", "FOR", "WHILE", "IF",
  "ELSE", "GOTO", "declblock", "codeblock", "IDENTIFIER", "ETOK",
  "SENTENCE", "INT", "COUT", "'['", "']'", "'}'", "'{'", "'('", "')'",
  "OO", "AA", "'&'", "':'", "'|'", "'\"'", "','", "'-'", "'+'", "ADDEQ",
  "SUBEQ", "'*'", "'/'", "'%'", "'^'", "'!'", "'='", "'<'", "'>'", "NE",
  "EE", "LE", "GE", "LS", "RS", "';'", "$accept", "Program",
  "Declaration_list", "Data_declaration", "Variables", "Variable", "Label",
  "Statement_list", "Forms", "Printparts", "Printpart", "Vars", "Assign",
  "Expr", "For", "Condition", "Bool_s", "While", "If", "Goto", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,    91,    93,   125,
     123,    40,    41,   272,   273,    38,    58,   124,    34,    44,
      45,    43,   274,   275,    42,    47,    37,    94,    33,    61,
      60,    62,   276,   277,   278,   279,   280,   281,    59
};
# endif

#define YYPACT_NINF -78

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-78)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       0,   -14,    23,    59,   -78,    15,    15,     9,   -78,    21,
     -16,   -78,   -15,    30,   -78,    54,    15,   -78,   -78,    40,
      68,   -78,   329,   -78,    63,     4,     4,    76,    28,    75,
     -78,    91,   -78,   314,   -78,   -78,   -78,   -78,   -78,    53,
     -78,    77,     4,    55,    55,   -78,   242,    57,   115,   106,
      -4,    55,   329,   -78,   -78,     8,   -78,   -78,   -78,   -78,
      55,    55,    56,    62,    55,    55,   152,   206,    55,   296,
     -26,    55,    55,    55,    55,    55,    55,    55,    55,   329,
       4,     4,    55,    55,    55,    55,    55,    55,   329,     4,
     -78,    97,   -78,    75,   -78,   160,   179,    55,    55,   187,
     207,   -78,   -78,   152,   296,   296,    18,    18,    18,   -26,
      61,   -78,   278,    78,   -78,    96,   133,   212,    39,    64,
     -78,   286,   -19,   -78,   -78,   -78,   -78,   215,   234,   -78,
      55,   -78,    98,   -78,   -78,   -78,   116,    84,   329,    55,
     329,   294,   134,   302,   -78,   329,   -78,   310,   -78
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     3,     9,
       0,     7,     0,     0,     4,     0,     0,     6,     5,     0,
       0,     8,     0,    10,     0,     0,     0,     0,    26,     0,
      19,     0,    13,     0,    16,    15,    14,    17,    18,     0,
      42,    26,     0,     0,     0,    41,    58,     0,    50,     0,
       0,     0,     0,    25,    24,     0,    22,    23,     2,    12,
       0,     0,     0,     0,     0,     0,    58,     0,     0,    43,
      44,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      63,     0,    11,     0,    20,     0,     0,     0,     0,     0,
       0,    45,    51,     0,    34,    33,    35,    36,    38,    40,
      39,    37,     0,    49,    48,    52,    53,    57,    56,    55,
      54,     0,     0,    27,    21,    29,    30,     0,     0,    28,
       0,    59,    60,    62,    31,    32,     0,     0,     0,     0,
       0,     0,     0,     0,    46,     0,    61,     0,    47
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -78,   -78,   -78,   105,   114,   108,   -78,   -77,   -30,   -78,
      29,   -22,   -78,   -25,   -78,   -11,   118,   -78,   -78,   -78
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     7,     8,    10,    11,    30,    31,    32,    55,
      56,    45,    34,    46,    35,    47,    48,    36,    37,    38
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      33,    59,   112,    89,    80,    81,     3,    57,    40,    33,
       1,   121,     5,    16,    16,    49,    41,    66,    69,    70,
      77,    78,    92,     4,     6,    42,    91,     9,    13,   133,
      33,    67,    17,    18,    43,    95,    96,    93,    15,    99,
     100,    19,    44,   103,    90,    51,   104,   105,   106,   107,
     108,   109,   110,   111,    52,    76,    94,    33,    20,    40,
      22,   141,     5,   143,    77,    78,    33,    41,   147,   113,
     114,    57,   127,   128,     6,    39,    68,    79,   122,    53,
      80,    81,    59,    86,    87,    43,    23,    41,    50,    54,
      33,    59,    65,    44,    51,    97,    24,    25,    26,    33,
      27,    98,    81,    28,   140,   136,   137,    29,    78,    87,
      58,    59,    14,    59,   142,   123,    33,    59,    33,    33,
      12,    33,   124,    33,    21,    33,    88,    71,    72,    80,
      81,    73,    74,    75,    76,     0,   138,    83,    84,    85,
      86,    87,     0,    77,    78,   139,    71,    72,     0,     0,
      73,    74,    75,    76,   145,    82,    83,    84,    85,    86,
      87,     0,    77,    78,    71,    72,     0,     0,    73,    74,
      75,    76,     0,     0,   101,    84,    85,    86,    87,     0,
      77,    78,    71,    72,     0,     0,    73,    74,    75,    76,
      71,    72,     0,     0,    73,    74,    75,    76,    77,    78,
     115,   116,   117,   118,   119,   120,    77,    78,   125,    71,
      72,     0,     0,    73,    74,    75,    76,    71,    72,     0,
       0,    73,    74,    75,    76,    77,    78,   126,   102,    80,
      81,     0,     0,    77,    78,   129,   130,    71,    72,     0,
       0,    73,    74,    75,    76,    71,    72,     0,     0,    73,
      74,    75,    76,    77,    78,    85,    86,    87,     0,     0,
       0,    77,    78,   134,    71,    72,     0,     0,    73,    74,
      75,    76,    71,    72,     0,     0,    73,    74,    75,    76,
      77,    78,   135,    24,    25,    26,     0,    27,    77,    78,
      28,    24,    25,    26,    29,    27,     0,   131,    28,    24,
      25,    26,    29,    27,     0,   132,    28,    24,    25,    26,
      29,    27,     0,   144,    28,    24,    25,    26,    29,    27,
       0,   146,    28,     0,     0,     0,    29,     0,     0,   148,
      73,    74,    75,    76,    24,    25,    26,     0,    27,     0,
       0,    28,    77,    78,     0,    29,    60,    61,    62,    63,
       0,     0,     0,    64
};

static const yytype_int16 yycheck[] =
{
      22,    31,    79,     7,    23,    24,    20,    29,     4,    31,
      10,    88,     3,    29,    29,    26,    12,    42,    43,    44,
      46,    47,    52,     0,    15,    21,    51,    12,    19,    48,
      52,    42,    48,    48,    30,    60,    61,    29,    17,    64,
      65,    11,    38,    68,    48,    17,    71,    72,    73,    74,
      75,    76,    77,    78,    26,    37,    48,    79,     4,     4,
      20,   138,     3,   140,    46,    47,    88,    12,   145,    80,
      81,    93,    97,    98,    15,    12,    21,    20,    89,     4,
      23,    24,   112,    44,    45,    30,    18,    12,    12,    14,
     112,   121,    39,    38,    17,    39,     5,     6,     7,   121,
       9,    39,    24,    12,    20,   130,     8,    16,    47,    45,
      19,   141,     7,   143,   139,    18,   138,   147,   140,   141,
       6,   143,    93,   145,    16,   147,    20,    30,    31,    23,
      24,    34,    35,    36,    37,    -1,    20,    41,    42,    43,
      44,    45,    -1,    46,    47,    29,    30,    31,    -1,    -1,
      34,    35,    36,    37,    20,    40,    41,    42,    43,    44,
      45,    -1,    46,    47,    30,    31,    -1,    -1,    34,    35,
      36,    37,    -1,    -1,    22,    42,    43,    44,    45,    -1,
      46,    47,    30,    31,    -1,    -1,    34,    35,    36,    37,
      30,    31,    -1,    -1,    34,    35,    36,    37,    46,    47,
      82,    83,    84,    85,    86,    87,    46,    47,    48,    30,
      31,    -1,    -1,    34,    35,    36,    37,    30,    31,    -1,
      -1,    34,    35,    36,    37,    46,    47,    48,    22,    23,
      24,    -1,    -1,    46,    47,    48,    29,    30,    31,    -1,
      -1,    34,    35,    36,    37,    30,    31,    -1,    -1,    34,
      35,    36,    37,    46,    47,    43,    44,    45,    -1,    -1,
      -1,    46,    47,    48,    30,    31,    -1,    -1,    34,    35,
      36,    37,    30,    31,    -1,    -1,    34,    35,    36,    37,
      46,    47,    48,     5,     6,     7,    -1,     9,    46,    47,
      12,     5,     6,     7,    16,     9,    -1,    19,    12,     5,
       6,     7,    16,     9,    -1,    19,    12,     5,     6,     7,
      16,     9,    -1,    19,    12,     5,     6,     7,    16,     9,
      -1,    19,    12,    -1,    -1,    -1,    16,    -1,    -1,    19,
      34,    35,    36,    37,     5,     6,     7,    -1,     9,    -1,
      -1,    12,    46,    47,    -1,    16,    32,    33,    34,    35,
      -1,    -1,    -1,    39
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    10,    50,    20,     0,     3,    15,    51,    52,    12,
      53,    54,    53,    19,    52,    17,    29,    48,    48,    11,
       4,    54,    20,    18,     5,     6,     7,     9,    12,    16,
      55,    56,    57,    60,    61,    63,    66,    67,    68,    12,
       4,    12,    21,    30,    38,    60,    62,    64,    65,    64,
      12,    17,    26,     4,    14,    58,    59,    60,    19,    57,
      32,    33,    34,    35,    39,    39,    62,    64,    21,    62,
      62,    30,    31,    34,    35,    36,    37,    46,    47,    20,
      23,    24,    40,    41,    42,    43,    44,    45,    20,     7,
      48,    62,    57,    29,    48,    62,    62,    39,    39,    62,
      62,    22,    22,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    56,    64,    64,    65,    65,    65,    65,    65,
      65,    56,    64,    18,    59,    48,    48,    62,    62,    48,
      29,    19,    19,    48,    48,    48,    62,     8,    20,    29,
      20,    56,    62,    56,    19,    20,    19,    56,    19
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    51,    51,    52,    52,    53,    53,    54,
      54,    55,    56,    56,    57,    57,    57,    57,    57,    57,
      57,    58,    58,    59,    59,    59,    60,    60,    61,    61,
      61,    61,    61,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    63,    63,    64,    64,
      64,    64,    65,    65,    65,    65,    65,    65,    65,    66,
      67,    67,    68,    68
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     8,     1,     2,     3,     3,     1,     3,     1,
       4,     3,     2,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     1,     1,     1,     1,     1,     4,     4,     4,
       4,     5,     5,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     2,     2,     3,     9,    11,     3,     3,
       1,     3,     3,     3,     3,     3,     3,     3,     1,     5,
       5,     9,     5,     3
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
        case 2:
#line 84 "parser.y" /* yacc.c:1646  */
    {
            (yyval.prog)=new Prog((yyvsp[-5].decl_list),(yyvsp[-1].st_list));
            start=(yyval.prog);
          }
#line 1366 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 90 "parser.y" /* yacc.c:1646  */
    { (yyval.decl_list)=new Decl_list();(yyval.decl_list)->push_back((yyvsp[0].decl_data));}
#line 1372 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 91 "parser.y" /* yacc.c:1646  */
    {(yyval.decl_list)->push_back((yyvsp[0].decl_data));}
#line 1378 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 93 "parser.y" /* yacc.c:1646  */
    {(yyval.decl_data)=new Decl_data(string((yyvsp[-2].value)),(yyvsp[-1].var_s));}
#line 1384 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 93 "parser.y" /* yacc.c:1646  */
    {(yyval.decl_data)=new Decl_data(string((yyvsp[-2].value)),(yyvsp[-1].var_s));}
#line 1390 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 95 "parser.y" /* yacc.c:1646  */
    {(yyval.var_s)=new Var_s();(yyval.var_s)->push_back((yyvsp[0].var));}
#line 1396 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 95 "parser.y" /* yacc.c:1646  */
    {(yyval.var_s)->push_back((yyvsp[0].var));}
#line 1402 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 97 "parser.y" /* yacc.c:1646  */
    {(yyval.var)=new Var(string("Normal"),(yyvsp[0].value));}
#line 1408 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 98 "parser.y" /* yacc.c:1646  */
    {(yyval.var)=new Var(string("Array"),string((yyvsp[-3].value)),(yyvsp[-1].number));}
#line 1414 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 106 "parser.y" /* yacc.c:1646  */
    {(yyval.label)=new Label((yyvsp[-2].value),(yyvsp[0].forms));}
#line 1420 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 108 "parser.y" /* yacc.c:1646  */
    {(yyval.st_list)->push_back((yyvsp[0].forms));}
#line 1426 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 109 "parser.y" /* yacc.c:1646  */
    {(yyval.st_list)=new St_list();(yyval.st_list)->push_back((yyvsp[0].forms));}
#line 1432 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 110 "parser.y" /* yacc.c:1646  */
    {(yyval.forms)=(yyvsp[0].while_l);}
#line 1438 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 111 "parser.y" /* yacc.c:1646  */
    {(yyval.forms)=(yyvsp[0].for_l);}
#line 1444 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 112 "parser.y" /* yacc.c:1646  */
    {(yyval.forms)=(yyvsp[0].assign);}
#line 1450 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 113 "parser.y" /* yacc.c:1646  */
    {(yyval.forms)=(yyvsp[0].if_l);}
#line 1456 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 114 "parser.y" /* yacc.c:1646  */
    {(yyval.forms)=(yyvsp[0].goto_l);}
#line 1462 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 115 "parser.y" /* yacc.c:1646  */
    {(yyval.forms)=(yyvsp[0].label);}
#line 1468 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 116 "parser.y" /* yacc.c:1646  */
    {(yyval.forms)=(yyvsp[-1].recPrint);}
#line 1474 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 119 "parser.y" /* yacc.c:1646  */
    {(yyval.recPrint)->push_back((yyvsp[0].Printpart));}
#line 1480 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 120 "parser.y" /* yacc.c:1646  */
    {(yyval.recPrint)=new recPrint(); (yyval.recPrint)->push_back((yyvsp[0].Printpart));}
#line 1486 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 122 "parser.y" /* yacc.c:1646  */
    {printf("scanner\n");(yyval.Printpart)=new VarPrint((yyvsp[0].vars));}
#line 1492 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 123 "parser.y" /* yacc.c:1646  */
    {printf("scanner111\n");(yyval.Printpart)=new SenPrint((yyvsp[0].value));}
#line 1498 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 124 "parser.y" /* yacc.c:1646  */
    {(yyval.Printpart)=new NumPrint((yyvsp[0].number));}
#line 1504 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 127 "parser.y" /* yacc.c:1646  */
    {(yyval.vars)=new Vars(string((yyvsp[0].value)),string("Normal"));}
#line 1510 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 128 "parser.y" /* yacc.c:1646  */
    {(yyval.vars)=new Vars(string((yyvsp[-3].value)),string("Array"),(yyvsp[-1].expression));}
#line 1516 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 132 "parser.y" /* yacc.c:1646  */
    {(yyval.assign)=new Assign((yyvsp[-3].vars),string("="),(yyvsp[-1].expression));}
#line 1522 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 133 "parser.y" /* yacc.c:1646  */
    {(yyval.assign)=new Assign((yyvsp[-3].vars),string("+="),(yyvsp[-1].expression));}
#line 1528 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 134 "parser.y" /* yacc.c:1646  */
    {(yyval.assign)=new Assign((yyvsp[-3].vars),string("-="),(yyvsp[-1].expression));}
#line 1534 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 135 "parser.y" /* yacc.c:1646  */
    {(yyval.assign)=new Assign((yyvsp[-4].vars),string("*="),(yyvsp[-1].expression));}
#line 1540 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 136 "parser.y" /* yacc.c:1646  */
    {(yyval.assign)=new Assign((yyvsp[-4].vars),string("/="),(yyvsp[-1].expression));}
#line 1546 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 139 "parser.y" /* yacc.c:1646  */
    {(yyval.expression)=new binExpr((yyvsp[-2].expression),string("+"),(yyvsp[0].expression));}
#line 1552 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 140 "parser.y" /* yacc.c:1646  */
    {(yyval.expression)=new binExpr((yyvsp[-2].expression),string("-"),(yyvsp[0].expression));}
#line 1558 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 141 "parser.y" /* yacc.c:1646  */
    {(yyval.expression)=new binExpr((yyvsp[-2].expression),string("*"),(yyvsp[0].expression));}
#line 1564 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 142 "parser.y" /* yacc.c:1646  */
    {(yyval.expression)=new binExpr((yyvsp[-2].expression),string("/"),(yyvsp[0].expression));}
#line 1570 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 143 "parser.y" /* yacc.c:1646  */
    {(yyval.expression)=new binExpr((yyvsp[-2].expression),string(">>"),(yyvsp[0].expression));}
#line 1576 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 144 "parser.y" /* yacc.c:1646  */
    {(yyval.expression)=new binExpr((yyvsp[-2].expression),string("%"),(yyvsp[0].expression));}
#line 1582 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 145 "parser.y" /* yacc.c:1646  */
    {(yyval.expression)=new binExpr((yyvsp[-2].expression),string("<<"),(yyvsp[0].expression));}
#line 1588 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 146 "parser.y" /* yacc.c:1646  */
    {(yyval.expression)=new binExpr((yyvsp[-2].expression),string("^"),(yyvsp[0].expression));}
#line 1594 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 147 "parser.y" /* yacc.c:1646  */
    {(yyval.expression) = (yyvsp[0].vars);}
#line 1600 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 148 "parser.y" /* yacc.c:1646  */
    {(yyval.expression) = new intLiteral((yyvsp[0].number));}
#line 1606 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 149 "parser.y" /* yacc.c:1646  */
    {(yyval.expression)=new unExpr(string("-"),(yyvsp[0].expression));}
#line 1612 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 150 "parser.y" /* yacc.c:1646  */
    {(yyval.expression)=new unExpr(string("!"),(yyvsp[0].expression));}
#line 1618 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 151 "parser.y" /* yacc.c:1646  */
    {(yyval.expression)=new EnclExpr((yyvsp[-1].expression));}
#line 1624 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 158 "parser.y" /* yacc.c:1646  */
    {(yyval.for_l)=new For_l((yyvsp[-7].value),(yyvsp[-5].expression),(yyvsp[-3].expression),NULL,(yyvsp[-1].st_list));}
#line 1630 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 160 "parser.y" /* yacc.c:1646  */
    {(yyval.for_l)=new For_l((yyvsp[-9].value),(yyvsp[-7].expression),(yyvsp[-5].expression),(yyvsp[-3].expression),(yyvsp[-1].st_list));}
#line 1636 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 162 "parser.y" /* yacc.c:1646  */
    {(yyval.cond)=new binCond((yyvsp[-2].cond),string("&&"),(yyvsp[0].cond));}
#line 1642 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 163 "parser.y" /* yacc.c:1646  */
    {(yyval.cond)=new binCond((yyvsp[-2].cond),string("||"),(yyvsp[0].cond));}
#line 1648 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 164 "parser.y" /* yacc.c:1646  */
    {(yyval.cond)=new boolCond((yyvsp[0].bool_s));}
#line 1654 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 165 "parser.y" /* yacc.c:1646  */
    {(yyval.cond)=new enclCond((yyvsp[-1].cond));}
#line 1660 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 166 "parser.y" /* yacc.c:1646  */
    {(yyval.bool_s)=new class binBool((yyvsp[-2].bool_s),string("<"),(yyvsp[0].bool_s));}
#line 1666 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 167 "parser.y" /* yacc.c:1646  */
    {(yyval.bool_s)=new class binBool((yyvsp[-2].bool_s),string(">"),(yyvsp[0].bool_s));}
#line 1672 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 168 "parser.y" /* yacc.c:1646  */
    {(yyval.bool_s)=new class binBool((yyvsp[-2].bool_s),string(">="),(yyvsp[0].bool_s));}
#line 1678 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 169 "parser.y" /* yacc.c:1646  */
    {(yyval.bool_s)=new class binBool((yyvsp[-2].bool_s),string("<="),(yyvsp[0].bool_s));}
#line 1684 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 170 "parser.y" /* yacc.c:1646  */
    {(yyval.bool_s)=new class binBool((yyvsp[-2].bool_s),string("=="),(yyvsp[0].bool_s));}
#line 1690 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 171 "parser.y" /* yacc.c:1646  */
    {(yyval.bool_s)=new class binBool((yyvsp[-2].bool_s),string("!="),(yyvsp[0].bool_s));}
#line 1696 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 172 "parser.y" /* yacc.c:1646  */
    {(yyval.bool_s)=new class exprBool((yyvsp[0].expression));}
#line 1702 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 174 "parser.y" /* yacc.c:1646  */
    {(yyval.while_l)=new While_l((yyvsp[-3].cond),(yyvsp[-1].st_list));}
#line 1708 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 176 "parser.y" /* yacc.c:1646  */
    {(yyval.if_l)=new Ifelse((yyvsp[-3].cond),(yyvsp[-1].st_list),NULL);}
#line 1714 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 177 "parser.y" /* yacc.c:1646  */
    {(yyval.if_l)=new Ifelse((yyvsp[-7].cond),(yyvsp[-5].st_list),(yyvsp[-1].st_list));}
#line 1720 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 180 "parser.y" /* yacc.c:1646  */
    {(yyval.goto_l)=new class Goto((yyvsp[-3].value),(yyvsp[-1].cond));}
#line 1726 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 181 "parser.y" /* yacc.c:1646  */
    {(yyval.goto_l)=new class Goto((yyvsp[-1].value),NULL);}
#line 1732 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 1736 "parser.tab.c" /* yacc.c:1646  */
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
#line 184 "parser.y" /* yacc.c:1906  */


void yyerror (char const *s)
{
       fprintf (stderr, "%s\n", s);
}

int main(int argc, char *argv[])
{
	if (argc == 1 ) {
		fprintf(stderr, "Correct usage: bcc filename\n");
		exit(1);
	}

	if (argc > 2) {
		fprintf(stderr, "Passing more arguments than necessary.\n");
		fprintf(stderr, "Correct usage: bcc filename\n");
	}

	yyin = fopen(argv[1], "r");

	yyparse();
  if(start){
      start->traverse();
      start->codegen();
      start->generateCode();
  }
}
