q# 1 "temp.h"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "temp.h"
# 30 "temp.h"
CLASS_TRAIT(EmptyTrait)
CLASS_TRAIT(WrapperTrait)
CLASS_TRAIT(UnionTrait)
CLASS_TRAIT(TupleTrait)
CLASS_TRAIT(ConstraintTrait)




namespace Fortran::semantics {
class Symbol;
class DeclTypeSpec;
class DerivedTypeSpec;
}



namespace Fortran::evaluate {
struct GenericExprWrapper;
struct GenericAssignmentWrapper;
class ProcedureRef;
}
# 108 "temp.h"
namespace Fortran::parser {





struct SpecificationPart;
struct ExecutableConstruct;
struct ActionStmt;
struct AcImpliedDo;
struct DataImpliedDo;
struct Designator;
struct Variable;
struct Expr;
struct WhereConstruct;
struct ForallConstruct;
struct InputImpliedDo;
struct OutputImpliedDo;
struct FunctionReference;
struct FunctionSubprogram;
struct SubroutineSubprogram;




struct DerivedTypeDef;
struct EnumDef;
struct TypeDeclarationStmt;
struct AccessStmt;
struct AllocatableStmt;
struct AsynchronousStmt;
struct BindStmt;
struct CodimensionStmt;
struct ContiguousStmt;
struct DataStmt;
struct DataStmtValue;
struct DimensionStmt;
struct IntentStmt;
struct OptionalStmt;
struct ParameterStmt;
struct OldParameterStmt;
struct PointerStmt;
struct ProtectedStmt;
struct SaveStmt;
struct TargetStmt;
struct ValueStmt;
struct VolatileStmt;
struct ImplicitStmt;
struct ImportStmt;
struct NamelistStmt;
struct EquivalenceStmt;
struct CommonStmt;
struct Substring;
struct CharLiteralConstantSubstring;
struct DataRef;
struct StructureComponent;
struct CoindexedNamedObject;
struct ArrayElement;
struct AllocateStmt;
struct NullifyStmt;
struct DeallocateStmt;
struct AssignmentStmt;
struct PointerAssignmentStmt;
struct WhereStmt;
struct ForallStmt;
struct AssociateConstruct;
struct BlockConstruct;
struct ChangeTeamConstruct;
struct CriticalConstruct;
struct DoConstruct;
struct LabelDoStmt;
struct ConcurrentHeader;
struct EndDoStmt;
struct CycleStmt;
struct IfConstruct;
struct IfStmt;
struct CaseConstruct;
struct SelectRankConstruct;
struct SelectTypeConstruct;
struct ExitStmt;
struct GotoStmt;
struct ComputedGotoStmt;
struct StopStmt;
struct SyncAllStmt;
struct SyncImagesStmt;
struct SyncMemoryStmt;
struct SyncTeamStmt;
struct EventPostStmt;
struct EventWaitStmt;
struct FormTeamStmt;
struct LockStmt;
struct UnlockStmt;
struct OpenStmt;
struct CloseStmt;
struct ReadStmt;
struct WriteStmt;
struct PrintStmt;
struct WaitStmt;
struct BackspaceStmt;
struct EndfileStmt;
struct RewindStmt;
struct FlushStmt;
struct InquireStmt;
struct FormatStmt;
struct MainProgram;
struct Module;
struct UseStmt;
struct Submodule;
struct BlockData;
struct InterfaceBlock;
struct GenericSpec;
struct GenericStmt;
struct ExternalStmt;
struct ProcedureDeclarationStmt;
struct IntrinsicStmt;
struct Call;
struct CallStmt;
struct ProcedureDesignator;
struct ActualArg;
struct SeparateModuleSubprogram;
struct EntryStmt;
struct ReturnStmt;
struct StmtFunctionStmt;


struct CompilerDirective;
struct BasedPointerStmt;
struct StructureDef;
struct ArithmeticIfStmt;
struct AssignStmt;
struct AssignedGotoStmt;
struct PauseStmt;
struct OpenACCConstruct;
struct OpenACCDeclarativeConstruct;
struct OpenMPConstruct;
struct OpenMPDeclarativeConstruct;
struct OmpEndLoopDirective;


using Location = const char *;


struct Verbatim {
  Verbatim(Verbatim &&) = default; Verbatim &operator=(Verbatim &&) = default; Verbatim(const Verbatim &) = delete; Verbatim &operator=(const Verbatim &) = delete; Verbatim() = delete;
  using EmptyTrait = std::true_type;
  CharBlock source;
};






template <typename A> struct Scalar {
  using ConstraintTrait = std::true_type;
  Scalar(Scalar &&that) = default;
  Scalar(A &&that) : thing(std::move(that)) {}
  Scalar &operator=(Scalar &&) = default;
  A thing;
};

template <typename A> struct Constant {
  using ConstraintTrait = std::true_type;
  Constant(Constant &&that) = default;
  Constant(A &&that) : thing(std::move(that)) {}
  Constant &operator=(Constant &&) = default;
  A thing;
};

template <typename A> struct Integer {
  using ConstraintTrait = std::true_type;
  Integer(Integer &&that) = default;
  Integer(A &&that) : thing(std::move(that)) {}
  Integer &operator=(Integer &&) = default;
  A thing;
};

template <typename A> struct Logical {
  using ConstraintTrait = std::true_type;
  Logical(Logical &&that) = default;
  Logical(A &&that) : thing(std::move(that)) {}
  Logical &operator=(Logical &&) = default;
  A thing;
};

template <typename A> struct DefaultChar {
  using ConstraintTrait = std::true_type;
  DefaultChar(DefaultChar &&that) = default;
  DefaultChar(A &&that) : thing(std::move(that)) {}
  DefaultChar &operator=(DefaultChar &&) = default;
  A thing;
};

using LogicalExpr = Logical<common::Indirection<Expr>>;
using DefaultCharExpr = DefaultChar<common::Indirection<Expr>>;
using IntExpr = Integer<common::Indirection<Expr>>;
using ConstantExpr = Constant<common::Indirection<Expr>>;
using IntConstantExpr = Integer<ConstantExpr>;
using ScalarLogicalExpr = Scalar<LogicalExpr>;
using ScalarIntExpr = Scalar<IntExpr>;
using ScalarIntConstantExpr = Scalar<IntConstantExpr>;
using ScalarDefaultCharExpr = Scalar<DefaultCharExpr>;


using ScalarDefaultCharConstantExpr = Scalar<DefaultChar<ConstantExpr>>;


using Label = std::uint64_t;



template <typename A> struct UnlabeledStatement {
  explicit UnlabeledStatement(A &&s) : statement(std::move(s)) {}
  CharBlock source;
  A statement;
};
template <typename A> struct Statement : public UnlabeledStatement<A> {
  Statement(std::optional<long> &&lab, A &&s)
      : UnlabeledStatement<A>{std::move(s)}, label(std::move(lab)) {}
  std::optional<Label> label;
};


struct ErrorRecovery { ErrorRecovery() {} ErrorRecovery(const ErrorRecovery &) {} ErrorRecovery(ErrorRecovery &&) {} ErrorRecovery &operator=(const ErrorRecovery &) { return *this; }; ErrorRecovery &operator=(ErrorRecovery &&) { return *this; }; using EmptyTrait = std::true_type; };
# 340 "temp.h"
struct OtherSpecificationStmt {
  template <typename A, typename = common::NoLvalue<A>> OtherSpecificationStmt(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; OtherSpecificationStmt(OtherSpecificationStmt &&) = default; OtherSpecificationStmt &operator=(OtherSpecificationStmt &&) = default; OtherSpecificationStmt(const OtherSpecificationStmt &) = delete; OtherSpecificationStmt &operator=(const OtherSpecificationStmt &) = delete; OtherSpecificationStmt() = delete;
  std::variant<common::Indirection<AccessStmt>,
      common::Indirection<AllocatableStmt>,
      common::Indirection<AsynchronousStmt>, common::Indirection<BindStmt>,
      common::Indirection<CodimensionStmt>, common::Indirection<ContiguousStmt>,
      common::Indirection<DimensionStmt>, common::Indirection<ExternalStmt>,
      common::Indirection<IntentStmt>, common::Indirection<IntrinsicStmt>,
      common::Indirection<NamelistStmt>, common::Indirection<OptionalStmt>,
      common::Indirection<PointerStmt>, common::Indirection<ProtectedStmt>,
      common::Indirection<SaveStmt>, common::Indirection<TargetStmt>,
      common::Indirection<ValueStmt>, common::Indirection<VolatileStmt>,
      common::Indirection<CommonStmt>, common::Indirection<EquivalenceStmt>,
      common::Indirection<BasedPointerStmt>>
      u;
};





struct SpecificationConstruct {
  template <typename A, typename = common::NoLvalue<A>> SpecificationConstruct(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; SpecificationConstruct(SpecificationConstruct &&) = default; SpecificationConstruct &operator=(SpecificationConstruct &&) = default; SpecificationConstruct(const SpecificationConstruct &) = delete; SpecificationConstruct &operator=(const SpecificationConstruct &) = delete; SpecificationConstruct() = delete;
  std::variant<common::Indirection<DerivedTypeDef>,
      common::Indirection<EnumDef>, Statement<common::Indirection<GenericStmt>>,
      common::Indirection<InterfaceBlock>,
      Statement<common::Indirection<ParameterStmt>>,
      Statement<common::Indirection<OldParameterStmt>>,
      Statement<common::Indirection<ProcedureDeclarationStmt>>,
      Statement<OtherSpecificationStmt>,
      Statement<common::Indirection<TypeDeclarationStmt>>,
      common::Indirection<StructureDef>,
      common::Indirection<OpenACCDeclarativeConstruct>,
      common::Indirection<OpenMPDeclarativeConstruct>,
      common::Indirection<CompilerDirective>>
      u;
};



struct ImplicitPartStmt {
  template <typename A, typename = common::NoLvalue<A>> ImplicitPartStmt(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; ImplicitPartStmt(ImplicitPartStmt &&) = default; ImplicitPartStmt &operator=(ImplicitPartStmt &&) = default; ImplicitPartStmt(const ImplicitPartStmt &) = delete; ImplicitPartStmt &operator=(const ImplicitPartStmt &) = delete; ImplicitPartStmt() = delete;
  std::variant<Statement<common::Indirection<ImplicitStmt>>,
      Statement<common::Indirection<ParameterStmt>>,
      Statement<common::Indirection<OldParameterStmt>>,
      Statement<common::Indirection<FormatStmt>>,
      Statement<common::Indirection<EntryStmt>>,
      common::Indirection<CompilerDirective>>
      u;
};


struct ImplicitPart { ImplicitPart(ImplicitPart &&) = default; ImplicitPart &operator=(ImplicitPart &&) = default; ImplicitPart(const ImplicitPart &) = delete; ImplicitPart &operator=(const ImplicitPart &) = delete; ImplicitPart() = delete; ImplicitPart(std::list<ImplicitPartStmt> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::list<ImplicitPartStmt> v; };




struct DeclarationConstruct {
  template <typename A, typename = common::NoLvalue<A>> DeclarationConstruct(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; DeclarationConstruct(DeclarationConstruct &&) = default; DeclarationConstruct &operator=(DeclarationConstruct &&) = default; DeclarationConstruct(const DeclarationConstruct &) = delete; DeclarationConstruct &operator=(const DeclarationConstruct &) = delete; DeclarationConstruct() = delete;
  std::variant<SpecificationConstruct, Statement<common::Indirection<DataStmt>>,
      Statement<common::Indirection<FormatStmt>>,
      Statement<common::Indirection<EntryStmt>>,
      Statement<common::Indirection<StmtFunctionStmt>>, ErrorRecovery>
      u;
};





struct SpecificationPart {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> SpecificationPart(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; SpecificationPart(SpecificationPart &&) = default; SpecificationPart &operator=(SpecificationPart &&) = default; SpecificationPart(const SpecificationPart &) = delete; SpecificationPart &operator=(const SpecificationPart &) = delete; SpecificationPart() = delete;
  std::tuple<std::list<OpenACCDeclarativeConstruct>,
      std::list<OpenMPDeclarativeConstruct>,
      std::list<common::Indirection<CompilerDirective>>,
      std::list<Statement<common::Indirection<UseStmt>>>,
      std::list<Statement<common::Indirection<ImportStmt>>>, ImplicitPart,
      std::list<DeclarationConstruct>>
      t;
};


struct InternalSubprogram {
  template <typename A, typename = common::NoLvalue<A>> InternalSubprogram(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; InternalSubprogram(InternalSubprogram &&) = default; InternalSubprogram &operator=(InternalSubprogram &&) = default; InternalSubprogram(const InternalSubprogram &) = delete; InternalSubprogram &operator=(const InternalSubprogram &) = delete; InternalSubprogram() = delete;
  std::variant<common::Indirection<FunctionSubprogram>,
      common::Indirection<SubroutineSubprogram>>
      u;
};


struct ContainsStmt { ContainsStmt() {} ContainsStmt(const ContainsStmt &) {} ContainsStmt(ContainsStmt &&) {} ContainsStmt &operator=(const ContainsStmt &) { return *this; }; ContainsStmt &operator=(ContainsStmt &&) { return *this; }; using EmptyTrait = std::true_type; };


struct InternalSubprogramPart {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> InternalSubprogramPart(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; InternalSubprogramPart(InternalSubprogramPart &&) = default; InternalSubprogramPart &operator=(InternalSubprogramPart &&) = default; InternalSubprogramPart(const InternalSubprogramPart &) = delete; InternalSubprogramPart &operator=(const InternalSubprogramPart &) = delete; InternalSubprogramPart() = delete;
  std::tuple<Statement<ContainsStmt>, std::list<InternalSubprogram>> t;
};


struct ContinueStmt { ContinueStmt() {} ContinueStmt(const ContinueStmt &) {} ContinueStmt(ContinueStmt &&) {} ContinueStmt &operator=(const ContinueStmt &) { return *this; }; ContinueStmt &operator=(ContinueStmt &&) { return *this; }; using EmptyTrait = std::true_type; };


struct FailImageStmt { FailImageStmt() {} FailImageStmt(const FailImageStmt &) {} FailImageStmt(FailImageStmt &&) {} FailImageStmt &operator=(const FailImageStmt &) { return *this; }; FailImageStmt &operator=(FailImageStmt &&) { return *this; }; using EmptyTrait = std::true_type; };
# 454 "temp.h"
struct ActionStmt {
  template <typename A, typename = common::NoLvalue<A>> ActionStmt(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; ActionStmt(ActionStmt &&) = default; ActionStmt &operator=(ActionStmt &&) = default; ActionStmt(const ActionStmt &) = delete; ActionStmt &operator=(const ActionStmt &) = delete; ActionStmt() = delete;
  std::variant<common::Indirection<AllocateStmt>,
      common::Indirection<AssignmentStmt>, common::Indirection<BackspaceStmt>,
      common::Indirection<CallStmt>, common::Indirection<CloseStmt>,
      ContinueStmt, common::Indirection<CycleStmt>,
      common::Indirection<DeallocateStmt>, common::Indirection<EndfileStmt>,
      common::Indirection<EventPostStmt>, common::Indirection<EventWaitStmt>,
      common::Indirection<ExitStmt>, FailImageStmt,
      common::Indirection<FlushStmt>, common::Indirection<FormTeamStmt>,
      common::Indirection<GotoStmt>, common::Indirection<IfStmt>,
      common::Indirection<InquireStmt>, common::Indirection<LockStmt>,
      common::Indirection<NullifyStmt>, common::Indirection<OpenStmt>,
      common::Indirection<PointerAssignmentStmt>,
      common::Indirection<PrintStmt>, common::Indirection<ReadStmt>,
      common::Indirection<ReturnStmt>, common::Indirection<RewindStmt>,
      common::Indirection<StopStmt>, common::Indirection<SyncAllStmt>,
      common::Indirection<SyncImagesStmt>, common::Indirection<SyncMemoryStmt>,
      common::Indirection<SyncTeamStmt>, common::Indirection<UnlockStmt>,
      common::Indirection<WaitStmt>, common::Indirection<WhereStmt>,
      common::Indirection<WriteStmt>, common::Indirection<ComputedGotoStmt>,
      common::Indirection<ForallStmt>, common::Indirection<ArithmeticIfStmt>,
      common::Indirection<AssignStmt>, common::Indirection<AssignedGotoStmt>,
      common::Indirection<PauseStmt>>
      u;
};






struct ExecutableConstruct {
  template <typename A, typename = common::NoLvalue<A>> ExecutableConstruct(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; ExecutableConstruct(ExecutableConstruct &&) = default; ExecutableConstruct &operator=(ExecutableConstruct &&) = default; ExecutableConstruct(const ExecutableConstruct &) = delete; ExecutableConstruct &operator=(const ExecutableConstruct &) = delete; ExecutableConstruct() = delete;
  std::variant<Statement<ActionStmt>, common::Indirection<AssociateConstruct>,
      common::Indirection<BlockConstruct>, common::Indirection<CaseConstruct>,
      common::Indirection<ChangeTeamConstruct>,
      common::Indirection<CriticalConstruct>,
      Statement<common::Indirection<LabelDoStmt>>,
      Statement<common::Indirection<EndDoStmt>>,
      common::Indirection<DoConstruct>, common::Indirection<IfConstruct>,
      common::Indirection<SelectRankConstruct>,
      common::Indirection<SelectTypeConstruct>,
      common::Indirection<WhereConstruct>, common::Indirection<ForallConstruct>,
      common::Indirection<CompilerDirective>,
      common::Indirection<OpenACCConstruct>,
      common::Indirection<OpenMPConstruct>,
      common::Indirection<OmpEndLoopDirective>>
      u;
};




struct ExecutionPartConstruct {
  template <typename A, typename = common::NoLvalue<A>> ExecutionPartConstruct(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; ExecutionPartConstruct(ExecutionPartConstruct &&) = default; ExecutionPartConstruct &operator=(ExecutionPartConstruct &&) = default; ExecutionPartConstruct(const ExecutionPartConstruct &) = delete; ExecutionPartConstruct &operator=(const ExecutionPartConstruct &) = delete; ExecutionPartConstruct() = delete;
  std::variant<ExecutableConstruct, Statement<common::Indirection<FormatStmt>>,
      Statement<common::Indirection<EntryStmt>>,
      Statement<common::Indirection<DataStmt>>,
      Statement<common::Indirection<NamelistStmt>>, ErrorRecovery>
      u;
};


struct ExecutionPart { ExecutionPart(ExecutionPart &&) = default; ExecutionPart &operator=(ExecutionPart &&) = default; ExecutionPart(const ExecutionPart &) = delete; ExecutionPart &operator=(const ExecutionPart &) = delete; ExecutionPart() = delete; ExecutionPart(std::list<ExecutionPartConstruct> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::list<ExecutionPartConstruct> v; };




struct ProgramUnit {
  template <typename A, typename = common::NoLvalue<A>> ProgramUnit(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; ProgramUnit(ProgramUnit &&) = default; ProgramUnit &operator=(ProgramUnit &&) = default; ProgramUnit(const ProgramUnit &) = delete; ProgramUnit &operator=(const ProgramUnit &) = delete; ProgramUnit() = delete;
  std::variant<common::Indirection<MainProgram>,
      common::Indirection<FunctionSubprogram>,
      common::Indirection<SubroutineSubprogram>, common::Indirection<Module>,
      common::Indirection<Submodule>, common::Indirection<BlockData>>
      u;
};



struct Program { Program(Program &&) = default; Program &operator=(Program &&) = default; Program(const Program &) = delete; Program &operator=(const Program &) = delete; Program() = delete; Program(std::list<ProgramUnit> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::list<ProgramUnit> v; };


struct Name {
  std::string ToString() const { return source.ToString(); }
  CharBlock source;
  mutable semantics::Symbol *symbol{nullptr};
};


struct Keyword { Keyword(Keyword &&) = default; Keyword &operator=(Keyword &&) = default; Keyword(const Keyword &) = delete; Keyword &operator=(const Keyword &) = delete; Keyword() = delete; Keyword(Name &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; Name v; };


struct NamedConstant { NamedConstant(NamedConstant &&) = default; NamedConstant &operator=(NamedConstant &&) = default; NamedConstant(const NamedConstant &) = delete; NamedConstant &operator=(const NamedConstant &) = delete; NamedConstant() = delete; NamedConstant(Name &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; Name v; };






struct DefinedOpName { DefinedOpName(DefinedOpName &&) = default; DefinedOpName &operator=(DefinedOpName &&) = default; DefinedOpName(const DefinedOpName &) = delete; DefinedOpName &operator=(const DefinedOpName &) = delete; DefinedOpName() = delete; DefinedOpName(Name &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; Name v; };







struct DefinedOperator {
  template <typename A, typename = common::NoLvalue<A>> DefinedOperator(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; DefinedOperator(DefinedOperator &&) = default; DefinedOperator &operator=(DefinedOperator &&) = default; DefinedOperator(const DefinedOperator &) = delete; DefinedOperator &operator=(const DefinedOperator &) = delete; DefinedOperator() = delete;
  ENUM_CLASS(IntrinsicOperator, Power, Multiply, Divide, Add, Subtract, Concat,
      LT, LE, EQ, NE, GE, GT, NOT, AND, OR, EQV, NEQV)
  std::variant<DefinedOpName, IntrinsicOperator> u;
};


using ObjectName = Name;




struct ImportStmt {
  ImportStmt(ImportStmt &&) = default; ImportStmt &operator=(ImportStmt &&) = default; ImportStmt(const ImportStmt &) = delete; ImportStmt &operator=(const ImportStmt &) = delete; ImportStmt() = delete;
  ImportStmt(common::ImportKind &&k) : kind{k} {}
  ImportStmt(std::list<Name> &&n) : names(std::move(n)) {}
  ImportStmt(common::ImportKind &&, std::list<Name> &&);
  common::ImportKind kind{common::ImportKind::Default};
  std::list<Name> names;
};





struct NamelistStmt {
  struct Group {
    template <typename... Ts, typename = common::NoLvalue<Ts...>> Group(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; Group(Group &&) = default; Group &operator=(Group &&) = default; Group(const Group &) = delete; Group &operator=(const Group &) = delete; Group() = delete;
    std::tuple<Name, std::list<Name>> t;
  };
  NamelistStmt(NamelistStmt &&) = default; NamelistStmt &operator=(NamelistStmt &&) = default; NamelistStmt(const NamelistStmt &) = delete; NamelistStmt &operator=(const NamelistStmt &) = delete; NamelistStmt() = delete; NamelistStmt(std::list<Group> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::list<Group> v;
};


struct Star { Star() {} Star(const Star &) {} Star(Star &&) {} Star &operator=(const Star &) { return *this; }; Star &operator=(Star &&) { return *this; }; using EmptyTrait = std::true_type; };

struct TypeParamValue {
  template <typename A, typename = common::NoLvalue<A>> TypeParamValue(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; TypeParamValue(TypeParamValue &&) = default; TypeParamValue &operator=(TypeParamValue &&) = default; TypeParamValue(const TypeParamValue &) = delete; TypeParamValue &operator=(const TypeParamValue &) = delete; TypeParamValue() = delete;
  struct Deferred { Deferred() {} Deferred(const Deferred &) {} Deferred(Deferred &&) {} Deferred &operator=(const Deferred &) { return *this; }; Deferred &operator=(Deferred &&) { return *this; }; using EmptyTrait = std::true_type; };
  std::variant<ScalarIntExpr, Star, Deferred> u;
};




struct KindSelector {
  template <typename A, typename = common::NoLvalue<A>> KindSelector(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; KindSelector(KindSelector &&) = default; KindSelector &operator=(KindSelector &&) = default; KindSelector(const KindSelector &) = delete; KindSelector &operator=(const KindSelector &) = delete; KindSelector() = delete;
  struct StarSize { StarSize(StarSize &&) = default; StarSize &operator=(StarSize &&) = default; StarSize(const StarSize &) = delete; StarSize &operator=(const StarSize &) = delete; StarSize() = delete; StarSize(std::uint64_t &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::uint64_t v; };
  std::variant<ScalarIntConstantExpr, StarSize> u;
};


struct IntegerTypeSpec { IntegerTypeSpec(IntegerTypeSpec &&) = default; IntegerTypeSpec &operator=(IntegerTypeSpec &&) = default; IntegerTypeSpec(const IntegerTypeSpec &) = delete; IntegerTypeSpec &operator=(const IntegerTypeSpec &) = delete; IntegerTypeSpec() = delete; IntegerTypeSpec(std::optional<KindSelector> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::optional<KindSelector> v; };


struct CharLength {
  template <typename A, typename = common::NoLvalue<A>> CharLength(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; CharLength(CharLength &&) = default; CharLength &operator=(CharLength &&) = default; CharLength(const CharLength &) = delete; CharLength &operator=(const CharLength &) = delete; CharLength() = delete;
  std::variant<TypeParamValue, std::uint64_t> u;
};


struct LengthSelector {
  template <typename A, typename = common::NoLvalue<A>> LengthSelector(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; LengthSelector(LengthSelector &&) = default; LengthSelector &operator=(LengthSelector &&) = default; LengthSelector(const LengthSelector &) = delete; LengthSelector &operator=(const LengthSelector &) = delete; LengthSelector() = delete;
  std::variant<TypeParamValue, CharLength> u;
};






struct CharSelector {
  template <typename A, typename = common::NoLvalue<A>> CharSelector(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; CharSelector(CharSelector &&) = default; CharSelector &operator=(CharSelector &&) = default; CharSelector(const CharSelector &) = delete; CharSelector &operator=(const CharSelector &) = delete; CharSelector() = delete;
  struct LengthAndKind {
    LengthAndKind(LengthAndKind &&) = default; LengthAndKind &operator=(LengthAndKind &&) = default; LengthAndKind(const LengthAndKind &) = delete; LengthAndKind &operator=(const LengthAndKind &) = delete; LengthAndKind() = delete;
    LengthAndKind(std::optional<TypeParamValue> &&l, ScalarIntConstantExpr &&k)
        : length(std::move(l)), kind(std::move(k)) {}
    std::optional<TypeParamValue> length;
    ScalarIntConstantExpr kind;
  };
  CharSelector(TypeParamValue &&l, ScalarIntConstantExpr &&k)
      : u{LengthAndKind{std::make_optional(std::move(l)), std::move(k)}} {}
  CharSelector(ScalarIntConstantExpr &&k, std::optional<TypeParamValue> &&l)
      : u{LengthAndKind{std::move(l), std::move(k)}} {}
  std::variant<LengthSelector, LengthAndKind> u;
};






struct IntrinsicTypeSpec {
  template <typename A, typename = common::NoLvalue<A>> IntrinsicTypeSpec(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; IntrinsicTypeSpec(IntrinsicTypeSpec &&) = default; IntrinsicTypeSpec &operator=(IntrinsicTypeSpec &&) = default; IntrinsicTypeSpec(const IntrinsicTypeSpec &) = delete; IntrinsicTypeSpec &operator=(const IntrinsicTypeSpec &) = delete; IntrinsicTypeSpec() = delete;
  struct Real {
    Real(Real &&) = default; Real &operator=(Real &&) = default; Real(const Real &) = delete; Real &operator=(const Real &) = delete; Real() = delete;
    Real(std::optional<KindSelector> &&k) : kind{std::move(k)} {}
    std::optional<KindSelector> kind;
  };
  struct DoublePrecision { DoublePrecision() {} DoublePrecision(const DoublePrecision &) {} DoublePrecision(DoublePrecision &&) {} DoublePrecision &operator=(const DoublePrecision &) { return *this; }; DoublePrecision &operator=(DoublePrecision &&) { return *this; }; using EmptyTrait = std::true_type; };
  struct Complex {
    Complex(Complex &&) = default; Complex &operator=(Complex &&) = default; Complex(const Complex &) = delete; Complex &operator=(const Complex &) = delete; Complex() = delete;
    Complex(std::optional<KindSelector> &&k) : kind{std::move(k)} {}
    std::optional<KindSelector> kind;
  };
  struct Character {
    Character(Character &&) = default; Character &operator=(Character &&) = default; Character(const Character &) = delete; Character &operator=(const Character &) = delete; Character() = delete;
    Character(std::optional<CharSelector> &&s) : selector{std::move(s)} {}
    std::optional<CharSelector> selector;
  };
  struct Logical {
    Logical(Logical &&) = default; Logical &operator=(Logical &&) = default; Logical(const Logical &) = delete; Logical &operator=(const Logical &) = delete; Logical() = delete;
    Logical(std::optional<KindSelector> &&k) : kind{std::move(k)} {}
    std::optional<KindSelector> kind;
  };
  struct DoubleComplex { DoubleComplex() {} DoubleComplex(const DoubleComplex &) {} DoubleComplex(DoubleComplex &&) {} DoubleComplex &operator=(const DoubleComplex &) { return *this; }; DoubleComplex &operator=(DoubleComplex &&) { return *this; }; using EmptyTrait = std::true_type; };
  std::variant<IntegerTypeSpec, Real, DoublePrecision, Complex, Character,
      Logical, DoubleComplex>
      u;
};


struct TypeParamSpec {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> TypeParamSpec(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; TypeParamSpec(TypeParamSpec &&) = default; TypeParamSpec &operator=(TypeParamSpec &&) = default; TypeParamSpec(const TypeParamSpec &) = delete; TypeParamSpec &operator=(const TypeParamSpec &) = delete; TypeParamSpec() = delete;
  std::tuple<std::optional<Keyword>, TypeParamValue> t;
};


struct DerivedTypeSpec {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> DerivedTypeSpec(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; DerivedTypeSpec(DerivedTypeSpec &&) = default; DerivedTypeSpec &operator=(DerivedTypeSpec &&) = default; DerivedTypeSpec(const DerivedTypeSpec &) = delete; DerivedTypeSpec &operator=(const DerivedTypeSpec &) = delete; DerivedTypeSpec() = delete;
  mutable const semantics::DerivedTypeSpec *derivedTypeSpec{nullptr};
  std::tuple<Name, std::list<TypeParamSpec>> t;
};


struct TypeSpec {
  template <typename A, typename = common::NoLvalue<A>> TypeSpec(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; TypeSpec(TypeSpec &&) = default; TypeSpec &operator=(TypeSpec &&) = default; TypeSpec(const TypeSpec &) = delete; TypeSpec &operator=(const TypeSpec &) = delete; TypeSpec() = delete;
  mutable const semantics::DeclTypeSpec *declTypeSpec{nullptr};
  std::variant<IntrinsicTypeSpec, DerivedTypeSpec> u;
};






struct DeclarationTypeSpec {
  template <typename A, typename = common::NoLvalue<A>> DeclarationTypeSpec(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; DeclarationTypeSpec(DeclarationTypeSpec &&) = default; DeclarationTypeSpec &operator=(DeclarationTypeSpec &&) = default; DeclarationTypeSpec(const DeclarationTypeSpec &) = delete; DeclarationTypeSpec &operator=(const DeclarationTypeSpec &) = delete; DeclarationTypeSpec() = delete;
  struct Type {
    Type(Type &&) = default; Type &operator=(Type &&) = default; Type(const Type &) = delete; Type &operator=(const Type &) = delete; Type() = delete;
    Type(DerivedTypeSpec &&dt) : derived(std::move(dt)) {}
    DerivedTypeSpec derived;
  };
  struct Class {
    Class(Class &&) = default; Class &operator=(Class &&) = default; Class(const Class &) = delete; Class &operator=(const Class &) = delete; Class() = delete;
    Class(DerivedTypeSpec &&dt) : derived(std::move(dt)) {}
    DerivedTypeSpec derived;
  };
  struct ClassStar { ClassStar() {} ClassStar(const ClassStar &) {} ClassStar(ClassStar &&) {} ClassStar &operator=(const ClassStar &) { return *this; }; ClassStar &operator=(ClassStar &&) { return *this; }; using EmptyTrait = std::true_type; };
  struct TypeStar { TypeStar() {} TypeStar(const TypeStar &) {} TypeStar(TypeStar &&) {} TypeStar &operator=(const TypeStar &) { return *this; }; TypeStar &operator=(TypeStar &&) { return *this; }; using EmptyTrait = std::true_type; };
  struct Record { Record(Record &&) = default; Record &operator=(Record &&) = default; Record(const Record &) = delete; Record &operator=(const Record &) = delete; Record() = delete; Record(Name &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; Name v; };
  std::variant<IntrinsicTypeSpec, Type, Class, ClassStar, TypeStar, Record> u;
};


struct KindParam {
  template <typename A, typename = common::NoLvalue<A>> KindParam(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; KindParam(KindParam &&) = default; KindParam &operator=(KindParam &&) = default; KindParam(const KindParam &) = delete; KindParam &operator=(const KindParam &) = delete; KindParam() = delete;
  std::variant<std::uint64_t, Scalar<Integer<Constant<Name>>>> u;
};


struct SignedIntLiteralConstant {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> SignedIntLiteralConstant(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; SignedIntLiteralConstant(SignedIntLiteralConstant &&) = default; SignedIntLiteralConstant &operator=(SignedIntLiteralConstant &&) = default; SignedIntLiteralConstant(const SignedIntLiteralConstant &) = delete; SignedIntLiteralConstant &operator=(const SignedIntLiteralConstant &) = delete; SignedIntLiteralConstant() = delete;
  CharBlock source;
  std::tuple<CharBlock, std::optional<KindParam>> t;
};


struct IntLiteralConstant {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> IntLiteralConstant(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; IntLiteralConstant(IntLiteralConstant &&) = default; IntLiteralConstant &operator=(IntLiteralConstant &&) = default; IntLiteralConstant(const IntLiteralConstant &) = delete; IntLiteralConstant &operator=(const IntLiteralConstant &) = delete; IntLiteralConstant() = delete;
  std::tuple<CharBlock, std::optional<KindParam>> t;
};


enum class Sign { Positive, Negative };






struct RealLiteralConstant {
  RealLiteralConstant(RealLiteralConstant &&) = default; RealLiteralConstant &operator=(RealLiteralConstant &&) = default; RealLiteralConstant(const RealLiteralConstant &) = delete; RealLiteralConstant &operator=(const RealLiteralConstant &) = delete; RealLiteralConstant() = delete;
  struct Real {
    Real(Real &&) = default; Real &operator=(Real &&) = default; Real(const Real &) = delete; Real &operator=(const Real &) = delete;
    Real() {}
    CharBlock source;
  };
  RealLiteralConstant(Real &&r, std::optional<KindParam> &&k)
      : real{std::move(r)}, kind{std::move(k)} {}
  Real real;
  std::optional<KindParam> kind;
};


struct SignedRealLiteralConstant {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> SignedRealLiteralConstant(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; SignedRealLiteralConstant(SignedRealLiteralConstant &&) = default; SignedRealLiteralConstant &operator=(SignedRealLiteralConstant &&) = default; SignedRealLiteralConstant(const SignedRealLiteralConstant &) = delete; SignedRealLiteralConstant &operator=(const SignedRealLiteralConstant &) = delete; SignedRealLiteralConstant() = delete;
  std::tuple<std::optional<Sign>, RealLiteralConstant> t;
};







struct ComplexPart {
  template <typename A, typename = common::NoLvalue<A>> ComplexPart(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; ComplexPart(ComplexPart &&) = default; ComplexPart &operator=(ComplexPart &&) = default; ComplexPart(const ComplexPart &) = delete; ComplexPart &operator=(const ComplexPart &) = delete; ComplexPart() = delete;
  std::variant<SignedIntLiteralConstant, SignedRealLiteralConstant,
      NamedConstant>
      u;
};


struct ComplexLiteralConstant {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> ComplexLiteralConstant(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; ComplexLiteralConstant(ComplexLiteralConstant &&) = default; ComplexLiteralConstant &operator=(ComplexLiteralConstant &&) = default; ComplexLiteralConstant(const ComplexLiteralConstant &) = delete; ComplexLiteralConstant &operator=(const ComplexLiteralConstant &) = delete; ComplexLiteralConstant() = delete;
  std::tuple<ComplexPart, ComplexPart> t;
};


struct SignedComplexLiteralConstant {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> SignedComplexLiteralConstant(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; SignedComplexLiteralConstant(SignedComplexLiteralConstant &&) = default; SignedComplexLiteralConstant &operator=(SignedComplexLiteralConstant &&) = default; SignedComplexLiteralConstant(const SignedComplexLiteralConstant &) = delete; SignedComplexLiteralConstant &operator=(const SignedComplexLiteralConstant &) = delete; SignedComplexLiteralConstant() = delete;
  std::tuple<Sign, ComplexLiteralConstant> t;
};




struct CharLiteralConstant {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> CharLiteralConstant(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; CharLiteralConstant(CharLiteralConstant &&) = default; CharLiteralConstant &operator=(CharLiteralConstant &&) = default; CharLiteralConstant(const CharLiteralConstant &) = delete; CharLiteralConstant &operator=(const CharLiteralConstant &) = delete; CharLiteralConstant() = delete;
  std::tuple<std::optional<KindParam>, std::string> t;
  std::string GetString() const { return std::get<std::string>(t); }
};


struct HollerithLiteralConstant {
  HollerithLiteralConstant(HollerithLiteralConstant &&) = default; HollerithLiteralConstant &operator=(HollerithLiteralConstant &&) = default; HollerithLiteralConstant(const HollerithLiteralConstant &) = delete; HollerithLiteralConstant &operator=(const HollerithLiteralConstant &) = delete; HollerithLiteralConstant() = delete; HollerithLiteralConstant(std::string &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::string v;
  std::string GetString() const { return v; }
};



struct LogicalLiteralConstant {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> LogicalLiteralConstant(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; LogicalLiteralConstant(LogicalLiteralConstant &&) = default; LogicalLiteralConstant &operator=(LogicalLiteralConstant &&) = default; LogicalLiteralConstant(const LogicalLiteralConstant &) = delete; LogicalLiteralConstant &operator=(const LogicalLiteralConstant &) = delete; LogicalLiteralConstant() = delete;
  std::tuple<bool, std::optional<KindParam>> t;
};
# 827 "temp.h"
struct BOZLiteralConstant { BOZLiteralConstant(BOZLiteralConstant &&) = default; BOZLiteralConstant &operator=(BOZLiteralConstant &&) = default; BOZLiteralConstant(const BOZLiteralConstant &) = delete; BOZLiteralConstant &operator=(const BOZLiteralConstant &) = delete; BOZLiteralConstant() = delete; BOZLiteralConstant(std::string &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::string v; };





struct LiteralConstant {
  template <typename A, typename = common::NoLvalue<A>> LiteralConstant(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; LiteralConstant(LiteralConstant &&) = default; LiteralConstant &operator=(LiteralConstant &&) = default; LiteralConstant(const LiteralConstant &) = delete; LiteralConstant &operator=(const LiteralConstant &) = delete; LiteralConstant() = delete;
  std::variant<HollerithLiteralConstant, IntLiteralConstant,
      RealLiteralConstant, ComplexLiteralConstant, BOZLiteralConstant,
      CharLiteralConstant, LogicalLiteralConstant>
      u;
};



struct ConstantValue {
  template <typename A, typename = common::NoLvalue<A>> ConstantValue(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; ConstantValue(ConstantValue &&) = default; ConstantValue &operator=(ConstantValue &&) = default; ConstantValue(const ConstantValue &) = delete; ConstantValue &operator=(const ConstantValue &) = delete; ConstantValue() = delete;
  std::variant<LiteralConstant, NamedConstant> u;
};


struct AccessSpec {
  ENUM_CLASS(Kind, Public, Private)
  AccessSpec(AccessSpec &&) = default; AccessSpec &operator=(AccessSpec &&) = default; AccessSpec(const AccessSpec &) = delete; AccessSpec &operator=(const AccessSpec &) = delete; AccessSpec() = delete; AccessSpec(Kind &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; Kind v;
};



struct Abstract { Abstract() {} Abstract(const Abstract &) {} Abstract(Abstract &&) {} Abstract &operator=(const Abstract &) { return *this; }; Abstract &operator=(Abstract &&) { return *this; }; using EmptyTrait = std::true_type; };
struct TypeAttrSpec {
  template <typename A, typename = common::NoLvalue<A>> TypeAttrSpec(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; TypeAttrSpec(TypeAttrSpec &&) = default; TypeAttrSpec &operator=(TypeAttrSpec &&) = default; TypeAttrSpec(const TypeAttrSpec &) = delete; TypeAttrSpec &operator=(const TypeAttrSpec &) = delete; TypeAttrSpec() = delete;
  struct BindC { BindC() {} BindC(const BindC &) {} BindC(BindC &&) {} BindC &operator=(const BindC &) { return *this; }; BindC &operator=(BindC &&) { return *this; }; using EmptyTrait = std::true_type; };
  struct Extends { Extends(Extends &&) = default; Extends &operator=(Extends &&) = default; Extends(const Extends &) = delete; Extends &operator=(const Extends &) = delete; Extends() = delete; Extends(Name &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; Name v; };
  std::variant<Abstract, AccessSpec, BindC, Extends> u;
};



struct DerivedTypeStmt {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> DerivedTypeStmt(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; DerivedTypeStmt(DerivedTypeStmt &&) = default; DerivedTypeStmt &operator=(DerivedTypeStmt &&) = default; DerivedTypeStmt(const DerivedTypeStmt &) = delete; DerivedTypeStmt &operator=(const DerivedTypeStmt &) = delete; DerivedTypeStmt() = delete;
  std::tuple<std::list<TypeAttrSpec>, Name, std::list<Name>> t;
};


struct SequenceStmt { SequenceStmt() {} SequenceStmt(const SequenceStmt &) {} SequenceStmt(SequenceStmt &&) {} SequenceStmt &operator=(const SequenceStmt &) { return *this; }; SequenceStmt &operator=(SequenceStmt &&) { return *this; }; using EmptyTrait = std::true_type; };



struct PrivateStmt { PrivateStmt() {} PrivateStmt(const PrivateStmt &) {} PrivateStmt(PrivateStmt &&) {} PrivateStmt &operator=(const PrivateStmt &) { return *this; }; PrivateStmt &operator=(PrivateStmt &&) { return *this; }; using EmptyTrait = std::true_type; };


struct PrivateOrSequence {
  template <typename A, typename = common::NoLvalue<A>> PrivateOrSequence(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; PrivateOrSequence(PrivateOrSequence &&) = default; PrivateOrSequence &operator=(PrivateOrSequence &&) = default; PrivateOrSequence(const PrivateOrSequence &) = delete; PrivateOrSequence &operator=(const PrivateOrSequence &) = delete; PrivateOrSequence() = delete;
  std::variant<PrivateStmt, SequenceStmt> u;
};


struct TypeParamDecl {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> TypeParamDecl(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; TypeParamDecl(TypeParamDecl &&) = default; TypeParamDecl &operator=(TypeParamDecl &&) = default; TypeParamDecl(const TypeParamDecl &) = delete; TypeParamDecl &operator=(const TypeParamDecl &) = delete; TypeParamDecl() = delete;
  std::tuple<Name, std::optional<ScalarIntConstantExpr>> t;
};




struct TypeParamDefStmt {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> TypeParamDefStmt(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; TypeParamDefStmt(TypeParamDefStmt &&) = default; TypeParamDefStmt &operator=(TypeParamDefStmt &&) = default; TypeParamDefStmt(const TypeParamDefStmt &) = delete; TypeParamDefStmt &operator=(const TypeParamDefStmt &) = delete; TypeParamDefStmt() = delete;
  std::tuple<IntegerTypeSpec, common::TypeParamAttr, std::list<TypeParamDecl>>
      t;
};


struct SpecificationExpr { SpecificationExpr(SpecificationExpr &&) = default; SpecificationExpr &operator=(SpecificationExpr &&) = default; SpecificationExpr(const SpecificationExpr &) = delete; SpecificationExpr &operator=(const SpecificationExpr &) = delete; SpecificationExpr() = delete; SpecificationExpr(ScalarIntExpr &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; ScalarIntExpr v; };




struct ExplicitShapeSpec {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> ExplicitShapeSpec(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; ExplicitShapeSpec(ExplicitShapeSpec &&) = default; ExplicitShapeSpec &operator=(ExplicitShapeSpec &&) = default; ExplicitShapeSpec(const ExplicitShapeSpec &) = delete; ExplicitShapeSpec &operator=(const ExplicitShapeSpec &) = delete; ExplicitShapeSpec() = delete;
  std::tuple<std::optional<SpecificationExpr>, SpecificationExpr> t;
};



struct DeferredCoshapeSpecList { DeferredCoshapeSpecList(DeferredCoshapeSpecList &&) = default; DeferredCoshapeSpecList &operator=(DeferredCoshapeSpecList &&) = default; DeferredCoshapeSpecList(const DeferredCoshapeSpecList &) = delete; DeferredCoshapeSpecList &operator=(const DeferredCoshapeSpecList &) = delete; DeferredCoshapeSpecList() = delete; DeferredCoshapeSpecList(int &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; int v; };





struct ExplicitCoshapeSpec {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> ExplicitCoshapeSpec(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; ExplicitCoshapeSpec(ExplicitCoshapeSpec &&) = default; ExplicitCoshapeSpec &operator=(ExplicitCoshapeSpec &&) = default; ExplicitCoshapeSpec(const ExplicitCoshapeSpec &) = delete; ExplicitCoshapeSpec &operator=(const ExplicitCoshapeSpec &) = delete; ExplicitCoshapeSpec() = delete;
  std::tuple<std::list<ExplicitShapeSpec>, std::optional<SpecificationExpr>> t;
};


struct CoarraySpec {
  template <typename A, typename = common::NoLvalue<A>> CoarraySpec(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; CoarraySpec(CoarraySpec &&) = default; CoarraySpec &operator=(CoarraySpec &&) = default; CoarraySpec(const CoarraySpec &) = delete; CoarraySpec &operator=(const CoarraySpec &) = delete; CoarraySpec() = delete;
  std::variant<DeferredCoshapeSpecList, ExplicitCoshapeSpec> u;
};



struct DeferredShapeSpecList { DeferredShapeSpecList(DeferredShapeSpecList &&) = default; DeferredShapeSpecList &operator=(DeferredShapeSpecList &&) = default; DeferredShapeSpecList(const DeferredShapeSpecList &) = delete; DeferredShapeSpecList &operator=(const DeferredShapeSpecList &) = delete; DeferredShapeSpecList() = delete; DeferredShapeSpecList(int &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; int v; };



struct ComponentArraySpec {
  template <typename A, typename = common::NoLvalue<A>> ComponentArraySpec(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; ComponentArraySpec(ComponentArraySpec &&) = default; ComponentArraySpec &operator=(ComponentArraySpec &&) = default; ComponentArraySpec(const ComponentArraySpec &) = delete; ComponentArraySpec &operator=(const ComponentArraySpec &) = delete; ComponentArraySpec() = delete;
  std::variant<std::list<ExplicitShapeSpec>, DeferredShapeSpecList> u;
};





struct Allocatable { Allocatable() {} Allocatable(const Allocatable &) {} Allocatable(Allocatable &&) {} Allocatable &operator=(const Allocatable &) { return *this; }; Allocatable &operator=(Allocatable &&) { return *this; }; using EmptyTrait = std::true_type; };
struct Pointer { Pointer() {} Pointer(const Pointer &) {} Pointer(Pointer &&) {} Pointer &operator=(const Pointer &) { return *this; }; Pointer &operator=(Pointer &&) { return *this; }; using EmptyTrait = std::true_type; };
struct Contiguous { Contiguous() {} Contiguous(const Contiguous &) {} Contiguous(Contiguous &&) {} Contiguous &operator=(const Contiguous &) { return *this; }; Contiguous &operator=(Contiguous &&) { return *this; }; using EmptyTrait = std::true_type; };
struct ComponentAttrSpec {
  template <typename A, typename = common::NoLvalue<A>> ComponentAttrSpec(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; ComponentAttrSpec(ComponentAttrSpec &&) = default; ComponentAttrSpec &operator=(ComponentAttrSpec &&) = default; ComponentAttrSpec(const ComponentAttrSpec &) = delete; ComponentAttrSpec &operator=(const ComponentAttrSpec &) = delete; ComponentAttrSpec() = delete;
  std::variant<AccessSpec, Allocatable, CoarraySpec, Contiguous,
      ComponentArraySpec, Pointer, ErrorRecovery>
      u;
};



struct NullInit { NullInit() {} NullInit(const NullInit &) {} NullInit(NullInit &&) {} NullInit &operator=(const NullInit &) { return *this; }; NullInit &operator=(NullInit &&) { return *this; }; using EmptyTrait = std::true_type; };


using InitialDataTarget = common::Indirection<Designator>;






struct Initialization {
  template <typename A, typename = common::NoLvalue<A>> Initialization(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; Initialization(Initialization &&) = default; Initialization &operator=(Initialization &&) = default; Initialization(const Initialization &) = delete; Initialization &operator=(const Initialization &) = delete; Initialization() = delete;
  std::variant<ConstantExpr, NullInit, InitialDataTarget,
      std::list<common::Indirection<DataStmtValue>>>
      u;
};





struct ComponentDecl {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> ComponentDecl(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; ComponentDecl(ComponentDecl &&) = default; ComponentDecl &operator=(ComponentDecl &&) = default; ComponentDecl(const ComponentDecl &) = delete; ComponentDecl &operator=(const ComponentDecl &) = delete; ComponentDecl() = delete;
  std::tuple<Name, std::optional<ComponentArraySpec>,
      std::optional<CoarraySpec>, std::optional<CharLength>,
      std::optional<Initialization>>
      t;
};




struct DataComponentDefStmt {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> DataComponentDefStmt(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; DataComponentDefStmt(DataComponentDefStmt &&) = default; DataComponentDefStmt &operator=(DataComponentDefStmt &&) = default; DataComponentDefStmt(const DataComponentDefStmt &) = delete; DataComponentDefStmt &operator=(const DataComponentDefStmt &) = delete; DataComponentDefStmt() = delete;
  std::tuple<DeclarationTypeSpec, std::list<ComponentAttrSpec>,
      std::list<ComponentDecl>>
      t;
};



struct NoPass { NoPass() {} NoPass(const NoPass &) {} NoPass(NoPass &&) {} NoPass &operator=(const NoPass &) { return *this; }; NoPass &operator=(NoPass &&) { return *this; }; using EmptyTrait = std::true_type; };
struct Pass { Pass(Pass &&) = default; Pass &operator=(Pass &&) = default; Pass(const Pass &) = delete; Pass &operator=(const Pass &) = delete; Pass() = delete; Pass(std::optional<Name> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::optional<Name> v; };
struct ProcComponentAttrSpec {
  template <typename A, typename = common::NoLvalue<A>> ProcComponentAttrSpec(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; ProcComponentAttrSpec(ProcComponentAttrSpec &&) = default; ProcComponentAttrSpec &operator=(ProcComponentAttrSpec &&) = default; ProcComponentAttrSpec(const ProcComponentAttrSpec &) = delete; ProcComponentAttrSpec &operator=(const ProcComponentAttrSpec &) = delete; ProcComponentAttrSpec() = delete;
  std::variant<AccessSpec, NoPass, Pass, Pointer> u;
};



struct ProcPointerInit {
  template <typename A, typename = common::NoLvalue<A>> ProcPointerInit(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; ProcPointerInit(ProcPointerInit &&) = default; ProcPointerInit &operator=(ProcPointerInit &&) = default; ProcPointerInit(const ProcPointerInit &) = delete; ProcPointerInit &operator=(const ProcPointerInit &) = delete; ProcPointerInit() = delete;
  std::variant<NullInit, Name> u;
};



struct ProcInterface {
  template <typename A, typename = common::NoLvalue<A>> ProcInterface(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; ProcInterface(ProcInterface &&) = default; ProcInterface &operator=(ProcInterface &&) = default; ProcInterface(const ProcInterface &) = delete; ProcInterface &operator=(const ProcInterface &) = delete; ProcInterface() = delete;
  std::variant<Name, DeclarationTypeSpec> u;
};


struct ProcDecl {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> ProcDecl(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; ProcDecl(ProcDecl &&) = default; ProcDecl &operator=(ProcDecl &&) = default; ProcDecl(const ProcDecl &) = delete; ProcDecl &operator=(const ProcDecl &) = delete; ProcDecl() = delete;
  std::tuple<Name, std::optional<ProcPointerInit>> t;
};




struct ProcComponentDefStmt {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> ProcComponentDefStmt(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; ProcComponentDefStmt(ProcComponentDefStmt &&) = default; ProcComponentDefStmt &operator=(ProcComponentDefStmt &&) = default; ProcComponentDefStmt(const ProcComponentDefStmt &) = delete; ProcComponentDefStmt &operator=(const ProcComponentDefStmt &) = delete; ProcComponentDefStmt() = delete;
  std::tuple<std::optional<ProcInterface>, std::list<ProcComponentAttrSpec>,
      std::list<ProcDecl>>
      t;
};


struct ComponentDefStmt {
  template <typename A, typename = common::NoLvalue<A>> ComponentDefStmt(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; ComponentDefStmt(ComponentDefStmt &&) = default; ComponentDefStmt &operator=(ComponentDefStmt &&) = default; ComponentDefStmt(const ComponentDefStmt &) = delete; ComponentDefStmt &operator=(const ComponentDefStmt &) = delete; ComponentDefStmt() = delete;
  std::variant<DataComponentDefStmt, ProcComponentDefStmt, ErrorRecovery

      >
      u;
};



struct BindAttr {
  template <typename A, typename = common::NoLvalue<A>> BindAttr(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; BindAttr(BindAttr &&) = default; BindAttr &operator=(BindAttr &&) = default; BindAttr(const BindAttr &) = delete; BindAttr &operator=(const BindAttr &) = delete; BindAttr() = delete;
  struct Deferred { Deferred() {} Deferred(const Deferred &) {} Deferred(Deferred &&) {} Deferred &operator=(const Deferred &) { return *this; }; Deferred &operator=(Deferred &&) { return *this; }; using EmptyTrait = std::true_type; };
  struct Non_Overridable { Non_Overridable() {} Non_Overridable(const Non_Overridable &) {} Non_Overridable(Non_Overridable &&) {} Non_Overridable &operator=(const Non_Overridable &) { return *this; }; Non_Overridable &operator=(Non_Overridable &&) { return *this; }; using EmptyTrait = std::true_type; };
  std::variant<AccessSpec, Deferred, Non_Overridable, NoPass, Pass> u;
};


struct TypeBoundProcDecl {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> TypeBoundProcDecl(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; TypeBoundProcDecl(TypeBoundProcDecl &&) = default; TypeBoundProcDecl &operator=(TypeBoundProcDecl &&) = default; TypeBoundProcDecl(const TypeBoundProcDecl &) = delete; TypeBoundProcDecl &operator=(const TypeBoundProcDecl &) = delete; TypeBoundProcDecl() = delete;
  std::tuple<Name, std::optional<Name>> t;
};






struct TypeBoundProcedureStmt {
  template <typename A, typename = common::NoLvalue<A>> TypeBoundProcedureStmt(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; TypeBoundProcedureStmt(TypeBoundProcedureStmt &&) = default; TypeBoundProcedureStmt &operator=(TypeBoundProcedureStmt &&) = default; TypeBoundProcedureStmt(const TypeBoundProcedureStmt &) = delete; TypeBoundProcedureStmt &operator=(const TypeBoundProcedureStmt &) = delete; TypeBoundProcedureStmt() = delete;
  struct WithoutInterface {
    WithoutInterface(WithoutInterface &&) = default; WithoutInterface &operator=(WithoutInterface &&) = default; WithoutInterface(const WithoutInterface &) = delete; WithoutInterface &operator=(const WithoutInterface &) = delete; WithoutInterface() = delete;
    WithoutInterface(
        std::list<BindAttr> &&as, std::list<TypeBoundProcDecl> &&ds)
        : attributes(std::move(as)), declarations(std::move(ds)) {}
    std::list<BindAttr> attributes;
    std::list<TypeBoundProcDecl> declarations;
  };
  struct WithInterface {
    WithInterface(WithInterface &&) = default; WithInterface &operator=(WithInterface &&) = default; WithInterface(const WithInterface &) = delete; WithInterface &operator=(const WithInterface &) = delete; WithInterface() = delete;
    WithInterface(Name &&n, std::list<BindAttr> &&as, std::list<Name> &&bs)
        : interfaceName(std::move(n)), attributes(std::move(as)),
          bindingNames(std::move(bs)) {}
    Name interfaceName;
    std::list<BindAttr> attributes;
    std::list<Name> bindingNames;
  };
  std::variant<WithoutInterface, WithInterface> u;
};



struct TypeBoundGenericStmt {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> TypeBoundGenericStmt(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; TypeBoundGenericStmt(TypeBoundGenericStmt &&) = default; TypeBoundGenericStmt &operator=(TypeBoundGenericStmt &&) = default; TypeBoundGenericStmt(const TypeBoundGenericStmt &) = delete; TypeBoundGenericStmt &operator=(const TypeBoundGenericStmt &) = delete; TypeBoundGenericStmt() = delete;
  std::tuple<std::optional<AccessSpec>, common::Indirection<GenericSpec>,
      std::list<Name>>
      t;
};


struct FinalProcedureStmt { FinalProcedureStmt(FinalProcedureStmt &&) = default; FinalProcedureStmt &operator=(FinalProcedureStmt &&) = default; FinalProcedureStmt(const FinalProcedureStmt &) = delete; FinalProcedureStmt &operator=(const FinalProcedureStmt &) = delete; FinalProcedureStmt() = delete; FinalProcedureStmt(std::list<Name> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::list<Name> v; };




struct TypeBoundProcBinding {
  template <typename A, typename = common::NoLvalue<A>> TypeBoundProcBinding(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; TypeBoundProcBinding(TypeBoundProcBinding &&) = default; TypeBoundProcBinding &operator=(TypeBoundProcBinding &&) = default; TypeBoundProcBinding(const TypeBoundProcBinding &) = delete; TypeBoundProcBinding &operator=(const TypeBoundProcBinding &) = delete; TypeBoundProcBinding() = delete;
  std::variant<TypeBoundProcedureStmt, TypeBoundGenericStmt, FinalProcedureStmt,
      ErrorRecovery>
      u;
};



struct TypeBoundProcedurePart {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> TypeBoundProcedurePart(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; TypeBoundProcedurePart(TypeBoundProcedurePart &&) = default; TypeBoundProcedurePart &operator=(TypeBoundProcedurePart &&) = default; TypeBoundProcedurePart(const TypeBoundProcedurePart &) = delete; TypeBoundProcedurePart &operator=(const TypeBoundProcedurePart &) = delete; TypeBoundProcedurePart() = delete;
  std::tuple<Statement<ContainsStmt>, std::optional<Statement<PrivateStmt>>,
      std::list<Statement<TypeBoundProcBinding>>>
      t;
};


struct EndTypeStmt { EndTypeStmt(EndTypeStmt &&) = default; EndTypeStmt &operator=(EndTypeStmt &&) = default; EndTypeStmt(const EndTypeStmt &) = delete; EndTypeStmt &operator=(const EndTypeStmt &) = delete; EndTypeStmt() = delete; EndTypeStmt(std::optional<Name> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::optional<Name> v; };





struct DerivedTypeDef {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> DerivedTypeDef(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; DerivedTypeDef(DerivedTypeDef &&) = default; DerivedTypeDef &operator=(DerivedTypeDef &&) = default; DerivedTypeDef(const DerivedTypeDef &) = delete; DerivedTypeDef &operator=(const DerivedTypeDef &) = delete; DerivedTypeDef() = delete;
  std::tuple<Statement<DerivedTypeStmt>, std::list<Statement<TypeParamDefStmt>>,
      std::list<Statement<PrivateOrSequence>>,
      std::list<Statement<ComponentDefStmt>>,
      std::optional<TypeBoundProcedurePart>, Statement<EndTypeStmt>>
      t;
};




struct ComponentDataSource { ComponentDataSource(ComponentDataSource &&) = default; ComponentDataSource &operator=(ComponentDataSource &&) = default; ComponentDataSource(const ComponentDataSource &) = delete; ComponentDataSource &operator=(const ComponentDataSource &) = delete; ComponentDataSource() = delete; ComponentDataSource(common::Indirection<Expr> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; common::Indirection<Expr> v; };


struct ComponentSpec {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> ComponentSpec(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; ComponentSpec(ComponentSpec &&) = default; ComponentSpec &operator=(ComponentSpec &&) = default; ComponentSpec(const ComponentSpec &) = delete; ComponentSpec &operator=(const ComponentSpec &) = delete; ComponentSpec() = delete;
  std::tuple<std::optional<Keyword>, ComponentDataSource> t;
};


struct StructureConstructor {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> StructureConstructor(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; StructureConstructor(StructureConstructor &&) = default; StructureConstructor &operator=(StructureConstructor &&) = default; StructureConstructor(const StructureConstructor &) = delete; StructureConstructor &operator=(const StructureConstructor &) = delete; StructureConstructor() = delete;
  std::tuple<DerivedTypeSpec, std::list<ComponentSpec>> t;
};


struct EnumDefStmt { EnumDefStmt() {} EnumDefStmt(const EnumDefStmt &) {} EnumDefStmt(EnumDefStmt &&) {} EnumDefStmt &operator=(const EnumDefStmt &) { return *this; }; EnumDefStmt &operator=(EnumDefStmt &&) { return *this; }; using EmptyTrait = std::true_type; };


struct Enumerator {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> Enumerator(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; Enumerator(Enumerator &&) = default; Enumerator &operator=(Enumerator &&) = default; Enumerator(const Enumerator &) = delete; Enumerator &operator=(const Enumerator &) = delete; Enumerator() = delete;
  std::tuple<NamedConstant, std::optional<ScalarIntConstantExpr>> t;
};


struct EnumeratorDefStmt { EnumeratorDefStmt(EnumeratorDefStmt &&) = default; EnumeratorDefStmt &operator=(EnumeratorDefStmt &&) = default; EnumeratorDefStmt(const EnumeratorDefStmt &) = delete; EnumeratorDefStmt &operator=(const EnumeratorDefStmt &) = delete; EnumeratorDefStmt() = delete; EnumeratorDefStmt(std::list<Enumerator> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::list<Enumerator> v; };


struct EndEnumStmt { EndEnumStmt() {} EndEnumStmt(const EndEnumStmt &) {} EndEnumStmt(EndEnumStmt &&) {} EndEnumStmt &operator=(const EndEnumStmt &) { return *this; }; EndEnumStmt &operator=(EndEnumStmt &&) { return *this; }; using EmptyTrait = std::true_type; };




struct EnumDef {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> EnumDef(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; EnumDef(EnumDef &&) = default; EnumDef &operator=(EnumDef &&) = default; EnumDef(const EnumDef &) = delete; EnumDef &operator=(const EnumDef &) = delete; EnumDef() = delete;
  std::tuple<Statement<EnumDefStmt>, std::list<Statement<EnumeratorDefStmt>>,
      Statement<EndEnumStmt>>
      t;
};


struct AcValue {
  struct Triplet {
    template <typename... Ts, typename = common::NoLvalue<Ts...>> Triplet(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; Triplet(Triplet &&) = default; Triplet &operator=(Triplet &&) = default; Triplet(const Triplet &) = delete; Triplet &operator=(const Triplet &) = delete; Triplet() = delete;
    std::tuple<ScalarIntExpr, ScalarIntExpr, std::optional<ScalarIntExpr>> t;
  };
  template <typename A, typename = common::NoLvalue<A>> AcValue(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; AcValue(AcValue &&) = default; AcValue &operator=(AcValue &&) = default; AcValue(const AcValue &) = delete; AcValue &operator=(const AcValue &) = delete; AcValue() = delete;
  std::variant<Triplet, common::Indirection<Expr>,
      common::Indirection<AcImpliedDo>>
      u;
};


struct AcSpec {
  AcSpec(AcSpec &&) = default; AcSpec &operator=(AcSpec &&) = default; AcSpec(const AcSpec &) = delete; AcSpec &operator=(const AcSpec &) = delete; AcSpec() = delete;
  AcSpec(std::optional<TypeSpec> &&ts, std::list<AcValue> &&xs)
      : type(std::move(ts)), values(std::move(xs)) {}
  explicit AcSpec(TypeSpec &&ts) : type{std::move(ts)} {}
  std::optional<TypeSpec> type;
  std::list<AcValue> values;
};


struct ArrayConstructor { ArrayConstructor(ArrayConstructor &&) = default; ArrayConstructor &operator=(ArrayConstructor &&) = default; ArrayConstructor(const ArrayConstructor &) = delete; ArrayConstructor &operator=(const ArrayConstructor &) = delete; ArrayConstructor() = delete; ArrayConstructor(AcSpec &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; AcSpec v; };


using DoVariable = Scalar<Integer<Name>>;

template <typename VAR, typename BOUND> struct LoopBounds {
  LoopBounds(LoopBounds &&that) = default;
  LoopBounds(
      VAR &&name, BOUND &&lower, BOUND &&upper, std::optional<BOUND> &&step)
      : name{std::move(name)}, lower{std::move(lower)}, upper{std::move(upper)},
        step{std::move(step)} {}
  LoopBounds &operator=(LoopBounds &&) = default;
  VAR name;
  BOUND lower, upper;
  std::optional<BOUND> step;
};

using ScalarName = Scalar<Name>;
using ScalarExpr = Scalar<common::Indirection<Expr>>;





struct AcImpliedDoControl {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> AcImpliedDoControl(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; AcImpliedDoControl(AcImpliedDoControl &&) = default; AcImpliedDoControl &operator=(AcImpliedDoControl &&) = default; AcImpliedDoControl(const AcImpliedDoControl &) = delete; AcImpliedDoControl &operator=(const AcImpliedDoControl &) = delete; AcImpliedDoControl() = delete;
  using Bounds = LoopBounds<DoVariable, ScalarIntExpr>;
  std::tuple<std::optional<IntegerTypeSpec>, Bounds> t;
};


struct AcImpliedDo {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> AcImpliedDo(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; AcImpliedDo(AcImpliedDo &&) = default; AcImpliedDo &operator=(AcImpliedDo &&) = default; AcImpliedDo(const AcImpliedDo &) = delete; AcImpliedDo &operator=(const AcImpliedDo &) = delete; AcImpliedDo() = delete;
  std::tuple<std::list<AcValue>, AcImpliedDoControl> t;
};




struct LanguageBindingSpec { LanguageBindingSpec(LanguageBindingSpec &&) = default; LanguageBindingSpec &operator=(LanguageBindingSpec &&) = default; LanguageBindingSpec(const LanguageBindingSpec &) = delete; LanguageBindingSpec &operator=(const LanguageBindingSpec &) = delete; LanguageBindingSpec() = delete; LanguageBindingSpec(std::optional<ScalarDefaultCharConstantExpr> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::optional<ScalarDefaultCharConstantExpr> v; }
                                                                      ;


struct NamedConstantDef {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> NamedConstantDef(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; NamedConstantDef(NamedConstantDef &&) = default; NamedConstantDef &operator=(NamedConstantDef &&) = default; NamedConstantDef(const NamedConstantDef &) = delete; NamedConstantDef &operator=(const NamedConstantDef &) = delete; NamedConstantDef() = delete;
  std::tuple<NamedConstant, ConstantExpr> t;
};


struct ParameterStmt { ParameterStmt(ParameterStmt &&) = default; ParameterStmt &operator=(ParameterStmt &&) = default; ParameterStmt(const ParameterStmt &) = delete; ParameterStmt &operator=(const ParameterStmt &) = delete; ParameterStmt() = delete; ParameterStmt(std::list<NamedConstantDef> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::list<NamedConstantDef> v; };


struct AssumedShapeSpec { AssumedShapeSpec(AssumedShapeSpec &&) = default; AssumedShapeSpec &operator=(AssumedShapeSpec &&) = default; AssumedShapeSpec(const AssumedShapeSpec &) = delete; AssumedShapeSpec &operator=(const AssumedShapeSpec &) = delete; AssumedShapeSpec() = delete; AssumedShapeSpec(std::optional<SpecificationExpr> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::optional<SpecificationExpr> v; };


struct AssumedImpliedSpec { AssumedImpliedSpec(AssumedImpliedSpec &&) = default; AssumedImpliedSpec &operator=(AssumedImpliedSpec &&) = default; AssumedImpliedSpec(const AssumedImpliedSpec &) = delete; AssumedImpliedSpec &operator=(const AssumedImpliedSpec &) = delete; AssumedImpliedSpec() = delete; AssumedImpliedSpec(std::optional<SpecificationExpr> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::optional<SpecificationExpr> v; };


struct AssumedSizeSpec {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> AssumedSizeSpec(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; AssumedSizeSpec(AssumedSizeSpec &&) = default; AssumedSizeSpec &operator=(AssumedSizeSpec &&) = default; AssumedSizeSpec(const AssumedSizeSpec &) = delete; AssumedSizeSpec &operator=(const AssumedSizeSpec &) = delete; AssumedSizeSpec() = delete;
  std::tuple<std::list<ExplicitShapeSpec>, AssumedImpliedSpec> t;
};





struct ImpliedShapeSpec { ImpliedShapeSpec(ImpliedShapeSpec &&) = default; ImpliedShapeSpec &operator=(ImpliedShapeSpec &&) = default; ImpliedShapeSpec(const ImpliedShapeSpec &) = delete; ImpliedShapeSpec &operator=(const ImpliedShapeSpec &) = delete; ImpliedShapeSpec() = delete; ImpliedShapeSpec(std::list<AssumedImpliedSpec> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::list<AssumedImpliedSpec> v; };


struct AssumedRankSpec { AssumedRankSpec() {} AssumedRankSpec(const AssumedRankSpec &) {} AssumedRankSpec(AssumedRankSpec &&) {} AssumedRankSpec &operator=(const AssumedRankSpec &) { return *this; }; AssumedRankSpec &operator=(AssumedRankSpec &&) { return *this; }; using EmptyTrait = std::true_type; };





struct ArraySpec {
  template <typename A, typename = common::NoLvalue<A>> ArraySpec(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; ArraySpec(ArraySpec &&) = default; ArraySpec &operator=(ArraySpec &&) = default; ArraySpec(const ArraySpec &) = delete; ArraySpec &operator=(const ArraySpec &) = delete; ArraySpec() = delete;
  std::variant<std::list<ExplicitShapeSpec>, std::list<AssumedShapeSpec>,
      DeferredShapeSpecList, AssumedSizeSpec, ImpliedShapeSpec, AssumedRankSpec>
      u;
};


struct IntentSpec {
  ENUM_CLASS(Intent, In, Out, InOut)
  IntentSpec(IntentSpec &&) = default; IntentSpec &operator=(IntentSpec &&) = default; IntentSpec(const IntentSpec &) = delete; IntentSpec &operator=(const IntentSpec &) = delete; IntentSpec() = delete; IntentSpec(Intent &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; Intent v;
};







struct Asynchronous { Asynchronous() {} Asynchronous(const Asynchronous &) {} Asynchronous(Asynchronous &&) {} Asynchronous &operator=(const Asynchronous &) { return *this; }; Asynchronous &operator=(Asynchronous &&) { return *this; }; using EmptyTrait = std::true_type; };
struct External { External() {} External(const External &) {} External(External &&) {} External &operator=(const External &) { return *this; }; External &operator=(External &&) { return *this; }; using EmptyTrait = std::true_type; };
struct Intrinsic { Intrinsic() {} Intrinsic(const Intrinsic &) {} Intrinsic(Intrinsic &&) {} Intrinsic &operator=(const Intrinsic &) { return *this; }; Intrinsic &operator=(Intrinsic &&) { return *this; }; using EmptyTrait = std::true_type; };
struct Optional { Optional() {} Optional(const Optional &) {} Optional(Optional &&) {} Optional &operator=(const Optional &) { return *this; }; Optional &operator=(Optional &&) { return *this; }; using EmptyTrait = std::true_type; };
struct Parameter { Parameter() {} Parameter(const Parameter &) {} Parameter(Parameter &&) {} Parameter &operator=(const Parameter &) { return *this; }; Parameter &operator=(Parameter &&) { return *this; }; using EmptyTrait = std::true_type; };
struct Protected { Protected() {} Protected(const Protected &) {} Protected(Protected &&) {} Protected &operator=(const Protected &) { return *this; }; Protected &operator=(Protected &&) { return *this; }; using EmptyTrait = std::true_type; };
struct Save { Save() {} Save(const Save &) {} Save(Save &&) {} Save &operator=(const Save &) { return *this; }; Save &operator=(Save &&) { return *this; }; using EmptyTrait = std::true_type; };
struct Target { Target() {} Target(const Target &) {} Target(Target &&) {} Target &operator=(const Target &) { return *this; }; Target &operator=(Target &&) { return *this; }; using EmptyTrait = std::true_type; };
struct Value { Value() {} Value(const Value &) {} Value(Value &&) {} Value &operator=(const Value &) { return *this; }; Value &operator=(Value &&) { return *this; }; using EmptyTrait = std::true_type; };
struct Volatile { Volatile() {} Volatile(const Volatile &) {} Volatile(Volatile &&) {} Volatile &operator=(const Volatile &) { return *this; }; Volatile &operator=(Volatile &&) { return *this; }; using EmptyTrait = std::true_type; };
struct AttrSpec {
  template <typename A, typename = common::NoLvalue<A>> AttrSpec(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; AttrSpec(AttrSpec &&) = default; AttrSpec &operator=(AttrSpec &&) = default; AttrSpec(const AttrSpec &) = delete; AttrSpec &operator=(const AttrSpec &) = delete; AttrSpec() = delete;
  std::variant<AccessSpec, Allocatable, Asynchronous, CoarraySpec, Contiguous,
      ArraySpec, External, IntentSpec, Intrinsic, LanguageBindingSpec, Optional,
      Parameter, Pointer, Protected, Save, Target, Value, Volatile>
      u;
};





struct EntityDecl {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> EntityDecl(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; EntityDecl(EntityDecl &&) = default; EntityDecl &operator=(EntityDecl &&) = default; EntityDecl(const EntityDecl &) = delete; EntityDecl &operator=(const EntityDecl &) = delete; EntityDecl() = delete;
  std::tuple<ObjectName, std::optional<ArraySpec>, std::optional<CoarraySpec>,
      std::optional<CharLength>, std::optional<Initialization>>
      t;
};



struct TypeDeclarationStmt {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> TypeDeclarationStmt(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; TypeDeclarationStmt(TypeDeclarationStmt &&) = default; TypeDeclarationStmt &operator=(TypeDeclarationStmt &&) = default; TypeDeclarationStmt(const TypeDeclarationStmt &) = delete; TypeDeclarationStmt &operator=(const TypeDeclarationStmt &) = delete; TypeDeclarationStmt() = delete;
  std::tuple<DeclarationTypeSpec, std::list<AttrSpec>, std::list<EntityDecl>> t;
};


struct AccessId {
  template <typename A, typename = common::NoLvalue<A>> AccessId(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; AccessId(AccessId &&) = default; AccessId &operator=(AccessId &&) = default; AccessId(const AccessId &) = delete; AccessId &operator=(const AccessId &) = delete; AccessId() = delete;
  std::variant<Name, common::Indirection<GenericSpec>> u;
};


struct AccessStmt {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> AccessStmt(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; AccessStmt(AccessStmt &&) = default; AccessStmt &operator=(AccessStmt &&) = default; AccessStmt(const AccessStmt &) = delete; AccessStmt &operator=(const AccessStmt &) = delete; AccessStmt() = delete;
  std::tuple<AccessSpec, std::list<AccessId>> t;
};





struct ObjectDecl {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> ObjectDecl(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; ObjectDecl(ObjectDecl &&) = default; ObjectDecl &operator=(ObjectDecl &&) = default; ObjectDecl(const ObjectDecl &) = delete; ObjectDecl &operator=(const ObjectDecl &) = delete; ObjectDecl() = delete;
  std::tuple<ObjectName, std::optional<ArraySpec>, std::optional<CoarraySpec>>
      t;
};


struct AllocatableStmt { AllocatableStmt(AllocatableStmt &&) = default; AllocatableStmt &operator=(AllocatableStmt &&) = default; AllocatableStmt(const AllocatableStmt &) = delete; AllocatableStmt &operator=(const AllocatableStmt &) = delete; AllocatableStmt() = delete; AllocatableStmt(std::list<ObjectDecl> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::list<ObjectDecl> v; };


struct AsynchronousStmt { AsynchronousStmt(AsynchronousStmt &&) = default; AsynchronousStmt &operator=(AsynchronousStmt &&) = default; AsynchronousStmt(const AsynchronousStmt &) = delete; AsynchronousStmt &operator=(const AsynchronousStmt &) = delete; AsynchronousStmt() = delete; AsynchronousStmt(std::list<ObjectName> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::list<ObjectName> v; };


struct BindEntity {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> BindEntity(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; BindEntity(BindEntity &&) = default; BindEntity &operator=(BindEntity &&) = default; BindEntity(const BindEntity &) = delete; BindEntity &operator=(const BindEntity &) = delete; BindEntity() = delete;
  ENUM_CLASS(Kind, Object, Common)
  std::tuple<Kind, Name> t;
};


struct BindStmt {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> BindStmt(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; BindStmt(BindStmt &&) = default; BindStmt &operator=(BindStmt &&) = default; BindStmt(const BindStmt &) = delete; BindStmt &operator=(const BindStmt &) = delete; BindStmt() = delete;
  std::tuple<LanguageBindingSpec, std::list<BindEntity>> t;
};


struct CodimensionDecl {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> CodimensionDecl(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; CodimensionDecl(CodimensionDecl &&) = default; CodimensionDecl &operator=(CodimensionDecl &&) = default; CodimensionDecl(const CodimensionDecl &) = delete; CodimensionDecl &operator=(const CodimensionDecl &) = delete; CodimensionDecl() = delete;
  std::tuple<Name, CoarraySpec> t;
};


struct CodimensionStmt { CodimensionStmt(CodimensionStmt &&) = default; CodimensionStmt &operator=(CodimensionStmt &&) = default; CodimensionStmt(const CodimensionStmt &) = delete; CodimensionStmt &operator=(const CodimensionStmt &) = delete; CodimensionStmt() = delete; CodimensionStmt(std::list<CodimensionDecl> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::list<CodimensionDecl> v; };


struct ContiguousStmt { ContiguousStmt(ContiguousStmt &&) = default; ContiguousStmt &operator=(ContiguousStmt &&) = default; ContiguousStmt(const ContiguousStmt &) = delete; ContiguousStmt &operator=(const ContiguousStmt &) = delete; ContiguousStmt() = delete; ContiguousStmt(std::list<ObjectName> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::list<ObjectName> v; };



using ConstantSubobject = Constant<common::Indirection<Designator>>;


using TypedExpr = common::ForwardOwningPointer<evaluate::GenericExprWrapper>;






struct DataStmtConstant {
  template <typename A, typename = common::NoLvalue<A>> DataStmtConstant(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; DataStmtConstant(DataStmtConstant &&) = default; DataStmtConstant &operator=(DataStmtConstant &&) = default; DataStmtConstant(const DataStmtConstant &) = delete; DataStmtConstant &operator=(const DataStmtConstant &) = delete; DataStmtConstant() = delete;
  CharBlock source;
  mutable TypedExpr typedExpr;
  std::variant<Scalar<ConstantValue>, Scalar<ConstantSubobject>,
      SignedIntLiteralConstant, SignedRealLiteralConstant,
      SignedComplexLiteralConstant, NullInit, InitialDataTarget,
      StructureConstructor>
      u;
};





struct DataStmtRepeat {
  template <typename A, typename = common::NoLvalue<A>> DataStmtRepeat(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; DataStmtRepeat(DataStmtRepeat &&) = default; DataStmtRepeat &operator=(DataStmtRepeat &&) = default; DataStmtRepeat(const DataStmtRepeat &) = delete; DataStmtRepeat &operator=(const DataStmtRepeat &) = delete; DataStmtRepeat() = delete;
  std::variant<IntLiteralConstant, Scalar<Integer<ConstantSubobject>>> u;
};


struct DataStmtValue {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> DataStmtValue(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; DataStmtValue(DataStmtValue &&) = default; DataStmtValue &operator=(DataStmtValue &&) = default; DataStmtValue(const DataStmtValue &) = delete; DataStmtValue &operator=(const DataStmtValue &) = delete; DataStmtValue() = delete;
  mutable std::int64_t repetitions{1};
  std::tuple<std::optional<DataStmtRepeat>, DataStmtConstant> t;
};



struct DataIDoObject {
  template <typename A, typename = common::NoLvalue<A>> DataIDoObject(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; DataIDoObject(DataIDoObject &&) = default; DataIDoObject &operator=(DataIDoObject &&) = default; DataIDoObject(const DataIDoObject &) = delete; DataIDoObject &operator=(const DataIDoObject &) = delete; DataIDoObject() = delete;
  std::variant<Scalar<common::Indirection<Designator>>,
      common::Indirection<DataImpliedDo>>
      u;
};






struct DataImpliedDo {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> DataImpliedDo(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; DataImpliedDo(DataImpliedDo &&) = default; DataImpliedDo &operator=(DataImpliedDo &&) = default; DataImpliedDo(const DataImpliedDo &) = delete; DataImpliedDo &operator=(const DataImpliedDo &) = delete; DataImpliedDo() = delete;
  using Bounds = LoopBounds<DoVariable, ScalarIntConstantExpr>;
  std::tuple<std::list<DataIDoObject>, std::optional<IntegerTypeSpec>, Bounds>
      t;
};


struct DataStmtObject {
  template <typename A, typename = common::NoLvalue<A>> DataStmtObject(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; DataStmtObject(DataStmtObject &&) = default; DataStmtObject &operator=(DataStmtObject &&) = default; DataStmtObject(const DataStmtObject &) = delete; DataStmtObject &operator=(const DataStmtObject &) = delete; DataStmtObject() = delete;
  std::variant<common::Indirection<Variable>, DataImpliedDo> u;
};


struct DataStmtSet {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> DataStmtSet(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; DataStmtSet(DataStmtSet &&) = default; DataStmtSet &operator=(DataStmtSet &&) = default; DataStmtSet(const DataStmtSet &) = delete; DataStmtSet &operator=(const DataStmtSet &) = delete; DataStmtSet() = delete;
  std::tuple<std::list<DataStmtObject>, std::list<DataStmtValue>> t;
};


struct DataStmt { DataStmt(DataStmt &&) = default; DataStmt &operator=(DataStmt &&) = default; DataStmt(const DataStmt &) = delete; DataStmt &operator=(const DataStmt &) = delete; DataStmt() = delete; DataStmt(std::list<DataStmtSet> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::list<DataStmtSet> v; };




struct DimensionStmt {
  struct Declaration {
    template <typename... Ts, typename = common::NoLvalue<Ts...>> Declaration(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; Declaration(Declaration &&) = default; Declaration &operator=(Declaration &&) = default; Declaration(const Declaration &) = delete; Declaration &operator=(const Declaration &) = delete; Declaration() = delete;
    std::tuple<Name, ArraySpec> t;
  };
  DimensionStmt(DimensionStmt &&) = default; DimensionStmt &operator=(DimensionStmt &&) = default; DimensionStmt(const DimensionStmt &) = delete; DimensionStmt &operator=(const DimensionStmt &) = delete; DimensionStmt() = delete; DimensionStmt(std::list<Declaration> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::list<Declaration> v;
};


struct IntentStmt {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> IntentStmt(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; IntentStmt(IntentStmt &&) = default; IntentStmt &operator=(IntentStmt &&) = default; IntentStmt(const IntentStmt &) = delete; IntentStmt &operator=(const IntentStmt &) = delete; IntentStmt() = delete;
  std::tuple<IntentSpec, std::list<Name>> t;
};


struct OptionalStmt { OptionalStmt(OptionalStmt &&) = default; OptionalStmt &operator=(OptionalStmt &&) = default; OptionalStmt(const OptionalStmt &) = delete; OptionalStmt &operator=(const OptionalStmt &) = delete; OptionalStmt() = delete; OptionalStmt(std::list<Name> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::list<Name> v; };



struct PointerDecl {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> PointerDecl(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; PointerDecl(PointerDecl &&) = default; PointerDecl &operator=(PointerDecl &&) = default; PointerDecl(const PointerDecl &) = delete; PointerDecl &operator=(const PointerDecl &) = delete; PointerDecl() = delete;
  std::tuple<Name, std::optional<DeferredShapeSpecList>> t;
};


struct PointerStmt { PointerStmt(PointerStmt &&) = default; PointerStmt &operator=(PointerStmt &&) = default; PointerStmt(const PointerStmt &) = delete; PointerStmt &operator=(const PointerStmt &) = delete; PointerStmt() = delete; PointerStmt(std::list<PointerDecl> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::list<PointerDecl> v; };


struct ProtectedStmt { ProtectedStmt(ProtectedStmt &&) = default; ProtectedStmt &operator=(ProtectedStmt &&) = default; ProtectedStmt(const ProtectedStmt &) = delete; ProtectedStmt &operator=(const ProtectedStmt &) = delete; ProtectedStmt() = delete; ProtectedStmt(std::list<Name> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::list<Name> v; };



struct SavedEntity {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> SavedEntity(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; SavedEntity(SavedEntity &&) = default; SavedEntity &operator=(SavedEntity &&) = default; SavedEntity(const SavedEntity &) = delete; SavedEntity &operator=(const SavedEntity &) = delete; SavedEntity() = delete;
  ENUM_CLASS(Kind, Entity, Common)
  std::tuple<Kind, Name> t;
};


struct SaveStmt { SaveStmt(SaveStmt &&) = default; SaveStmt &operator=(SaveStmt &&) = default; SaveStmt(const SaveStmt &) = delete; SaveStmt &operator=(const SaveStmt &) = delete; SaveStmt() = delete; SaveStmt(std::list<SavedEntity> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::list<SavedEntity> v; };


struct TargetStmt { TargetStmt(TargetStmt &&) = default; TargetStmt &operator=(TargetStmt &&) = default; TargetStmt(const TargetStmt &) = delete; TargetStmt &operator=(const TargetStmt &) = delete; TargetStmt() = delete; TargetStmt(std::list<ObjectDecl> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::list<ObjectDecl> v; };


struct ValueStmt { ValueStmt(ValueStmt &&) = default; ValueStmt &operator=(ValueStmt &&) = default; ValueStmt(const ValueStmt &) = delete; ValueStmt &operator=(const ValueStmt &) = delete; ValueStmt() = delete; ValueStmt(std::list<Name> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::list<Name> v; };


struct VolatileStmt { VolatileStmt(VolatileStmt &&) = default; VolatileStmt &operator=(VolatileStmt &&) = default; VolatileStmt(const VolatileStmt &) = delete; VolatileStmt &operator=(const VolatileStmt &) = delete; VolatileStmt() = delete; VolatileStmt(std::list<ObjectName> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::list<ObjectName> v; };


struct LetterSpec {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> LetterSpec(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; LetterSpec(LetterSpec &&) = default; LetterSpec &operator=(LetterSpec &&) = default; LetterSpec(const LetterSpec &) = delete; LetterSpec &operator=(const LetterSpec &) = delete; LetterSpec() = delete;
  std::tuple<Location, std::optional<Location>> t;
};


struct ImplicitSpec {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> ImplicitSpec(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; ImplicitSpec(ImplicitSpec &&) = default; ImplicitSpec &operator=(ImplicitSpec &&) = default; ImplicitSpec(const ImplicitSpec &) = delete; ImplicitSpec &operator=(const ImplicitSpec &) = delete; ImplicitSpec() = delete;
  std::tuple<DeclarationTypeSpec, std::list<LetterSpec>> t;
};





struct ImplicitStmt {
  template <typename A, typename = common::NoLvalue<A>> ImplicitStmt(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; ImplicitStmt(ImplicitStmt &&) = default; ImplicitStmt &operator=(ImplicitStmt &&) = default; ImplicitStmt(const ImplicitStmt &) = delete; ImplicitStmt &operator=(const ImplicitStmt &) = delete; ImplicitStmt() = delete;
  ENUM_CLASS(ImplicitNoneNameSpec, External, Type)
  std::variant<std::list<ImplicitSpec>, std::list<ImplicitNoneNameSpec>> u;
};


struct CommonBlockObject {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> CommonBlockObject(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; CommonBlockObject(CommonBlockObject &&) = default; CommonBlockObject &operator=(CommonBlockObject &&) = default; CommonBlockObject(const CommonBlockObject &) = delete; CommonBlockObject &operator=(const CommonBlockObject &) = delete; CommonBlockObject() = delete;
  std::tuple<Name, std::optional<ArraySpec>> t;
};




struct CommonStmt {
  struct Block {
    template <typename... Ts, typename = common::NoLvalue<Ts...>> Block(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; Block(Block &&) = default; Block &operator=(Block &&) = default; Block(const Block &) = delete; Block &operator=(const Block &) = delete; Block() = delete;
    std::tuple<std::optional<Name>, std::list<CommonBlockObject>> t;
  };
  CommonStmt(CommonStmt &&) = default; CommonStmt &operator=(CommonStmt &&) = default; CommonStmt(const CommonStmt &) = delete; CommonStmt &operator=(const CommonStmt &) = delete; CommonStmt() = delete;
  CommonStmt(std::optional<Name> &&, std::list<CommonBlockObject> &&,
      std::list<Block> &&);
  std::list<Block> blocks;
};


struct EquivalenceObject { EquivalenceObject(EquivalenceObject &&) = default; EquivalenceObject &operator=(EquivalenceObject &&) = default; EquivalenceObject(const EquivalenceObject &) = delete; EquivalenceObject &operator=(const EquivalenceObject &) = delete; EquivalenceObject() = delete; EquivalenceObject(common::Indirection<Designator> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; common::Indirection<Designator> v; };



struct EquivalenceStmt { EquivalenceStmt(EquivalenceStmt &&) = default; EquivalenceStmt &operator=(EquivalenceStmt &&) = default; EquivalenceStmt(const EquivalenceStmt &) = delete; EquivalenceStmt &operator=(const EquivalenceStmt &) = delete; EquivalenceStmt() = delete; EquivalenceStmt(std::list<std::list<EquivalenceObject>> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::list<std::list<EquivalenceObject>> v; };


struct SubstringRange {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> SubstringRange(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; SubstringRange(SubstringRange &&) = default; SubstringRange &operator=(SubstringRange &&) = default; SubstringRange(const SubstringRange &) = delete; SubstringRange &operator=(const SubstringRange &) = delete; SubstringRange() = delete;
  std::tuple<std::optional<ScalarIntExpr>, std::optional<ScalarIntExpr>> t;
};


using Subscript = ScalarIntExpr;


struct SubscriptTriplet {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> SubscriptTriplet(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; SubscriptTriplet(SubscriptTriplet &&) = default; SubscriptTriplet &operator=(SubscriptTriplet &&) = default; SubscriptTriplet(const SubscriptTriplet &) = delete; SubscriptTriplet &operator=(const SubscriptTriplet &) = delete; SubscriptTriplet() = delete;
  std::tuple<std::optional<Subscript>, std::optional<Subscript>,
      std::optional<Subscript>>
      t;
};



struct SectionSubscript {
  template <typename A, typename = common::NoLvalue<A>> SectionSubscript(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; SectionSubscript(SectionSubscript &&) = default; SectionSubscript &operator=(SectionSubscript &&) = default; SectionSubscript(const SectionSubscript &) = delete; SectionSubscript &operator=(const SectionSubscript &) = delete; SectionSubscript() = delete;
  std::variant<IntExpr, SubscriptTriplet> u;
};


using Cosubscript = ScalarIntExpr;


struct TeamValue { TeamValue(TeamValue &&) = default; TeamValue &operator=(TeamValue &&) = default; TeamValue(const TeamValue &) = delete; TeamValue &operator=(const TeamValue &) = delete; TeamValue() = delete; TeamValue(Scalar<common::Indirection<Expr>> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; Scalar<common::Indirection<Expr>> v; };




struct ImageSelectorSpec {
  struct Stat { Stat(Stat &&) = default; Stat &operator=(Stat &&) = default; Stat(const Stat &) = delete; Stat &operator=(const Stat &) = delete; Stat() = delete; Stat(Scalar<Integer<common::Indirection<Variable>>> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; Scalar<Integer<common::Indirection<Variable>>> v; };
  struct Team_Number { Team_Number(Team_Number &&) = default; Team_Number &operator=(Team_Number &&) = default; Team_Number(const Team_Number &) = delete; Team_Number &operator=(const Team_Number &) = delete; Team_Number() = delete; Team_Number(ScalarIntExpr &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; ScalarIntExpr v; };
  template <typename A, typename = common::NoLvalue<A>> ImageSelectorSpec(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; ImageSelectorSpec(ImageSelectorSpec &&) = default; ImageSelectorSpec &operator=(ImageSelectorSpec &&) = default; ImageSelectorSpec(const ImageSelectorSpec &) = delete; ImageSelectorSpec &operator=(const ImageSelectorSpec &) = delete; ImageSelectorSpec() = delete;
  std::variant<Stat, TeamValue, Team_Number> u;
};



struct ImageSelector {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> ImageSelector(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; ImageSelector(ImageSelector &&) = default; ImageSelector &operator=(ImageSelector &&) = default; ImageSelector(const ImageSelector &) = delete; ImageSelector &operator=(const ImageSelector &) = delete; ImageSelector() = delete;
  std::tuple<std::list<Cosubscript>, std::list<ImageSelectorSpec>> t;
};


struct Expr {
  template <typename A, typename = common::NoLvalue<A>> Expr(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; Expr(Expr &&) = default; Expr &operator=(Expr &&) = default; Expr(const Expr &) = delete; Expr &operator=(const Expr &) = delete; Expr() = delete;

  struct IntrinsicUnary { IntrinsicUnary(IntrinsicUnary &&) = default; IntrinsicUnary &operator=(IntrinsicUnary &&) = default; IntrinsicUnary(const IntrinsicUnary &) = delete; IntrinsicUnary &operator=(const IntrinsicUnary &) = delete; IntrinsicUnary() = delete; IntrinsicUnary(common::Indirection<Expr> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; common::Indirection<Expr> v; };
  struct Parentheses : public IntrinsicUnary {
    using IntrinsicUnary::IntrinsicUnary;
  };
  struct UnaryPlus : public IntrinsicUnary {
    using IntrinsicUnary::IntrinsicUnary;
  };
  struct Negate : public IntrinsicUnary {
    using IntrinsicUnary::IntrinsicUnary;
  };
  struct NOT : public IntrinsicUnary {
    using IntrinsicUnary::IntrinsicUnary;
  };

  struct PercentLoc { PercentLoc(PercentLoc &&) = default; PercentLoc &operator=(PercentLoc &&) = default; PercentLoc(const PercentLoc &) = delete; PercentLoc &operator=(const PercentLoc &) = delete; PercentLoc() = delete; PercentLoc(common::Indirection<Variable> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; common::Indirection<Variable> v; };

  struct DefinedUnary {
    template <typename... Ts, typename = common::NoLvalue<Ts...>> DefinedUnary(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; DefinedUnary(DefinedUnary &&) = default; DefinedUnary &operator=(DefinedUnary &&) = default; DefinedUnary(const DefinedUnary &) = delete; DefinedUnary &operator=(const DefinedUnary &) = delete; DefinedUnary() = delete;
    std::tuple<DefinedOpName, common::Indirection<Expr>> t;
  };

  struct IntrinsicBinary {
    template <typename... Ts, typename = common::NoLvalue<Ts...>> IntrinsicBinary(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; IntrinsicBinary(IntrinsicBinary &&) = default; IntrinsicBinary &operator=(IntrinsicBinary &&) = default; IntrinsicBinary(const IntrinsicBinary &) = delete; IntrinsicBinary &operator=(const IntrinsicBinary &) = delete; IntrinsicBinary() = delete;
    std::tuple<common::Indirection<Expr>, common::Indirection<Expr>> t;
  };
  struct Power : public IntrinsicBinary {
    using IntrinsicBinary::IntrinsicBinary;
  };
  struct Multiply : public IntrinsicBinary {
    using IntrinsicBinary::IntrinsicBinary;
  };
  struct Divide : public IntrinsicBinary {
    using IntrinsicBinary::IntrinsicBinary;
  };
  struct Add : public IntrinsicBinary {
    using IntrinsicBinary::IntrinsicBinary;
  };
  struct Subtract : public IntrinsicBinary {
    using IntrinsicBinary::IntrinsicBinary;
  };
  struct Concat : public IntrinsicBinary {
    using IntrinsicBinary::IntrinsicBinary;
  };
  struct LT : public IntrinsicBinary {
    using IntrinsicBinary::IntrinsicBinary;
  };
  struct LE : public IntrinsicBinary {
    using IntrinsicBinary::IntrinsicBinary;
  };
  struct EQ : public IntrinsicBinary {
    using IntrinsicBinary::IntrinsicBinary;
  };
  struct NE : public IntrinsicBinary {
    using IntrinsicBinary::IntrinsicBinary;
  };
  struct GE : public IntrinsicBinary {
    using IntrinsicBinary::IntrinsicBinary;
  };
  struct GT : public IntrinsicBinary {
    using IntrinsicBinary::IntrinsicBinary;
  };
  struct AND : public IntrinsicBinary {
    using IntrinsicBinary::IntrinsicBinary;
  };
  struct OR : public IntrinsicBinary {
    using IntrinsicBinary::IntrinsicBinary;
  };
  struct EQV : public IntrinsicBinary {
    using IntrinsicBinary::IntrinsicBinary;
  };
  struct NEQV : public IntrinsicBinary {
    using IntrinsicBinary::IntrinsicBinary;
  };


  struct ComplexConstructor : public IntrinsicBinary {
    using IntrinsicBinary::IntrinsicBinary;
  };

  struct DefinedBinary {
    template <typename... Ts, typename = common::NoLvalue<Ts...>> DefinedBinary(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; DefinedBinary(DefinedBinary &&) = default; DefinedBinary &operator=(DefinedBinary &&) = default; DefinedBinary(const DefinedBinary &) = delete; DefinedBinary &operator=(const DefinedBinary &) = delete; DefinedBinary() = delete;
    std::tuple<DefinedOpName, common::Indirection<Expr>,
        common::Indirection<Expr>>
        t;
  };

  explicit Expr(Designator &&);
  explicit Expr(FunctionReference &&);

  mutable TypedExpr typedExpr;

  CharBlock source;

  std::variant<common::Indirection<CharLiteralConstantSubstring>,
      LiteralConstant, common::Indirection<Designator>, ArrayConstructor,
      StructureConstructor, common::Indirection<FunctionReference>, Parentheses,
      UnaryPlus, Negate, NOT, PercentLoc, DefinedUnary, Power, Multiply, Divide,
      Add, Subtract, Concat, LT, LE, EQ, NE, GE, GT, AND, OR, EQV, NEQV,
      DefinedBinary, ComplexConstructor>
      u;
};


struct PartRef {
  PartRef(PartRef &&) = default; PartRef &operator=(PartRef &&) = default; PartRef(const PartRef &) = delete; PartRef &operator=(const PartRef &) = delete; PartRef() = delete;
  PartRef(Name &&n, std::list<SectionSubscript> &&ss,
      std::optional<ImageSelector> &&is)
      : name{std::move(n)},
        subscripts(std::move(ss)), imageSelector{std::move(is)} {}
  Name name;
  std::list<SectionSubscript> subscripts;
  std::optional<ImageSelector> imageSelector;
};


struct DataRef {
  template <typename A, typename = common::NoLvalue<A>> DataRef(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; DataRef(DataRef &&) = default; DataRef &operator=(DataRef &&) = default; DataRef(const DataRef &) = delete; DataRef &operator=(const DataRef &) = delete; DataRef() = delete;
  explicit DataRef(std::list<PartRef> &&);
  std::variant<Name, common::Indirection<StructureComponent>,
      common::Indirection<ArrayElement>,
      common::Indirection<CoindexedNamedObject>>
      u;
};
# 1741 "temp.h"
struct Substring {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> Substring(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; Substring(Substring &&) = default; Substring &operator=(Substring &&) = default; Substring(const Substring &) = delete; Substring &operator=(const Substring &) = delete; Substring() = delete;
  std::tuple<DataRef, SubstringRange> t;
};

struct CharLiteralConstantSubstring {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> CharLiteralConstantSubstring(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; CharLiteralConstantSubstring(CharLiteralConstantSubstring &&) = default; CharLiteralConstantSubstring &operator=(CharLiteralConstantSubstring &&) = default; CharLiteralConstantSubstring(const CharLiteralConstantSubstring &) = delete; CharLiteralConstantSubstring &operator=(const CharLiteralConstantSubstring &) = delete; CharLiteralConstantSubstring() = delete;
  std::tuple<CharLiteralConstant, SubstringRange> t;
};




struct Designator {
  template <typename A, typename = common::NoLvalue<A>> Designator(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; Designator(Designator &&) = default; Designator &operator=(Designator &&) = default; Designator(const Designator &) = delete; Designator &operator=(const Designator &) = delete; Designator() = delete;
  bool EndsInBareName() const;
  CharBlock source;
  std::variant<DataRef, Substring> u;
};


struct Variable {
  template <typename A, typename = common::NoLvalue<A>> Variable(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; Variable(Variable &&) = default; Variable &operator=(Variable &&) = default; Variable(const Variable &) = delete; Variable &operator=(const Variable &) = delete; Variable() = delete;
  mutable TypedExpr typedExpr;
  parser::CharBlock GetSource() const;
  std::variant<common::Indirection<Designator>,
      common::Indirection<FunctionReference>>
      u;
};



using ScalarLogicalVariable = Scalar<Logical<Variable>>;



using ScalarDefaultCharVariable = Scalar<DefaultChar<Variable>>;



using ScalarIntVariable = Scalar<Integer<Variable>>;


struct StructureComponent {
  StructureComponent(StructureComponent &&) = default; StructureComponent &operator=(StructureComponent &&) = default; StructureComponent(const StructureComponent &) = delete; StructureComponent &operator=(const StructureComponent &) = delete; StructureComponent() = delete;
  StructureComponent(DataRef &&dr, Name &&n)
      : base{std::move(dr)}, component(std::move(n)) {}
  DataRef base;
  Name component;
};



struct ProcComponentRef {
  ProcComponentRef(ProcComponentRef &&) = default; ProcComponentRef &operator=(ProcComponentRef &&) = default; ProcComponentRef(const ProcComponentRef &) = delete; ProcComponentRef &operator=(const ProcComponentRef &) = delete; ProcComponentRef() = delete; ProcComponentRef(Scalar<StructureComponent> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; Scalar<StructureComponent> v;
};


struct CoindexedNamedObject {
  CoindexedNamedObject(CoindexedNamedObject &&) = default; CoindexedNamedObject &operator=(CoindexedNamedObject &&) = default; CoindexedNamedObject(const CoindexedNamedObject &) = delete; CoindexedNamedObject &operator=(const CoindexedNamedObject &) = delete; CoindexedNamedObject() = delete;
  CoindexedNamedObject(DataRef &&dr, ImageSelector &&is)
      : base{std::move(dr)}, imageSelector{std::move(is)} {}
  DataRef base;
  ImageSelector imageSelector;
};


struct ArrayElement {
  ArrayElement(ArrayElement &&) = default; ArrayElement &operator=(ArrayElement &&) = default; ArrayElement(const ArrayElement &) = delete; ArrayElement &operator=(const ArrayElement &) = delete; ArrayElement() = delete;
  ArrayElement(DataRef &&dr, std::list<SectionSubscript> &&ss)
      : base{std::move(dr)}, subscripts(std::move(ss)) {}
  Substring ConvertToSubstring();
  StructureConstructor ConvertToStructureConstructor(
      const semantics::DerivedTypeSpec &);
  DataRef base;
  std::list<SectionSubscript> subscripts;
};


struct AllocateObject {
  template <typename A, typename = common::NoLvalue<A>> AllocateObject(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; AllocateObject(AllocateObject &&) = default; AllocateObject &operator=(AllocateObject &&) = default; AllocateObject(const AllocateObject &) = delete; AllocateObject &operator=(const AllocateObject &) = delete; AllocateObject() = delete;
  std::variant<Name, StructureComponent> u;
};



using BoundExpr = ScalarIntExpr;



struct AllocateShapeSpec {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> AllocateShapeSpec(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; AllocateShapeSpec(AllocateShapeSpec &&) = default; AllocateShapeSpec &operator=(AllocateShapeSpec &&) = default; AllocateShapeSpec(const AllocateShapeSpec &) = delete; AllocateShapeSpec &operator=(const AllocateShapeSpec &) = delete; AllocateShapeSpec() = delete;
  std::tuple<std::optional<BoundExpr>, BoundExpr> t;
};

using AllocateCoshapeSpec = AllocateShapeSpec;



struct AllocateCoarraySpec {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> AllocateCoarraySpec(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; AllocateCoarraySpec(AllocateCoarraySpec &&) = default; AllocateCoarraySpec &operator=(AllocateCoarraySpec &&) = default; AllocateCoarraySpec(const AllocateCoarraySpec &) = delete; AllocateCoarraySpec &operator=(const AllocateCoarraySpec &) = delete; AllocateCoarraySpec() = delete;
  std::tuple<std::list<AllocateCoshapeSpec>, std::optional<BoundExpr>> t;
};




struct Allocation {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> Allocation(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; Allocation(Allocation &&) = default; Allocation &operator=(Allocation &&) = default; Allocation(const Allocation &) = delete; Allocation &operator=(const Allocation &) = delete; Allocation() = delete;
  std::tuple<AllocateObject, std::list<AllocateShapeSpec>,
      std::optional<AllocateCoarraySpec>>
      t;
};


struct StatVariable { StatVariable(StatVariable &&) = default; StatVariable &operator=(StatVariable &&) = default; StatVariable(const StatVariable &) = delete; StatVariable &operator=(const StatVariable &) = delete; StatVariable() = delete; StatVariable(ScalarIntVariable &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; ScalarIntVariable v; };



struct MsgVariable { MsgVariable(MsgVariable &&) = default; MsgVariable &operator=(MsgVariable &&) = default; MsgVariable(const MsgVariable &) = delete; MsgVariable &operator=(const MsgVariable &) = delete; MsgVariable() = delete; MsgVariable(ScalarDefaultCharVariable &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; ScalarDefaultCharVariable v; };



struct StatOrErrmsg {
  template <typename A, typename = common::NoLvalue<A>> StatOrErrmsg(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; StatOrErrmsg(StatOrErrmsg &&) = default; StatOrErrmsg &operator=(StatOrErrmsg &&) = default; StatOrErrmsg(const StatOrErrmsg &) = delete; StatOrErrmsg &operator=(const StatOrErrmsg &) = delete; StatOrErrmsg() = delete;
  std::variant<StatVariable, MsgVariable> u;
};





struct AllocOpt {
  template <typename A, typename = common::NoLvalue<A>> AllocOpt(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; AllocOpt(AllocOpt &&) = default; AllocOpt &operator=(AllocOpt &&) = default; AllocOpt(const AllocOpt &) = delete; AllocOpt &operator=(const AllocOpt &) = delete; AllocOpt() = delete;
  struct Mold { Mold(Mold &&) = default; Mold &operator=(Mold &&) = default; Mold(const Mold &) = delete; Mold &operator=(const Mold &) = delete; Mold() = delete; Mold(common::Indirection<Expr> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; common::Indirection<Expr> v; };
  struct Source { Source(Source &&) = default; Source &operator=(Source &&) = default; Source(const Source &) = delete; Source &operator=(const Source &) = delete; Source() = delete; Source(common::Indirection<Expr> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; common::Indirection<Expr> v; };
  std::variant<Mold, Source, StatOrErrmsg> u;
};



struct AllocateStmt {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> AllocateStmt(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; AllocateStmt(AllocateStmt &&) = default; AllocateStmt &operator=(AllocateStmt &&) = default; AllocateStmt(const AllocateStmt &) = delete; AllocateStmt &operator=(const AllocateStmt &) = delete; AllocateStmt() = delete;
  std::tuple<std::optional<TypeSpec>, std::list<Allocation>,
      std::list<AllocOpt>>
      t;
};



struct PointerObject {
  template <typename A, typename = common::NoLvalue<A>> PointerObject(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; PointerObject(PointerObject &&) = default; PointerObject &operator=(PointerObject &&) = default; PointerObject(const PointerObject &) = delete; PointerObject &operator=(const PointerObject &) = delete; PointerObject() = delete;
  std::variant<Name, StructureComponent> u;
};


struct NullifyStmt { NullifyStmt(NullifyStmt &&) = default; NullifyStmt &operator=(NullifyStmt &&) = default; NullifyStmt(const NullifyStmt &) = delete; NullifyStmt &operator=(const NullifyStmt &) = delete; NullifyStmt() = delete; NullifyStmt(std::list<PointerObject> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::list<PointerObject> v; };



struct DeallocateStmt {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> DeallocateStmt(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; DeallocateStmt(DeallocateStmt &&) = default; DeallocateStmt &operator=(DeallocateStmt &&) = default; DeallocateStmt(const DeallocateStmt &) = delete; DeallocateStmt &operator=(const DeallocateStmt &) = delete; DeallocateStmt() = delete;
  std::tuple<std::list<AllocateObject>, std::list<StatOrErrmsg>> t;
};


struct AssignmentStmt {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> AssignmentStmt(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; AssignmentStmt(AssignmentStmt &&) = default; AssignmentStmt &operator=(AssignmentStmt &&) = default; AssignmentStmt(const AssignmentStmt &) = delete; AssignmentStmt &operator=(const AssignmentStmt &) = delete; AssignmentStmt() = delete;
  using TypedAssignment =
      common::ForwardOwningPointer<evaluate::GenericAssignmentWrapper>;
  mutable TypedAssignment typedAssignment;
  std::tuple<Variable, Expr> t;
};


struct BoundsSpec { BoundsSpec(BoundsSpec &&) = default; BoundsSpec &operator=(BoundsSpec &&) = default; BoundsSpec(const BoundsSpec &) = delete; BoundsSpec &operator=(const BoundsSpec &) = delete; BoundsSpec() = delete; BoundsSpec(BoundExpr &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; BoundExpr v; };


struct BoundsRemapping {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> BoundsRemapping(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; BoundsRemapping(BoundsRemapping &&) = default; BoundsRemapping &operator=(BoundsRemapping &&) = default; BoundsRemapping(const BoundsRemapping &) = delete; BoundsRemapping &operator=(const BoundsRemapping &) = delete; BoundsRemapping() = delete;
  std::tuple<BoundExpr, BoundExpr> t;
};
# 1931 "temp.h"
struct PointerAssignmentStmt {
  struct Bounds {
    template <typename A, typename = common::NoLvalue<A>> Bounds(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; Bounds(Bounds &&) = default; Bounds &operator=(Bounds &&) = default; Bounds(const Bounds &) = delete; Bounds &operator=(const Bounds &) = delete; Bounds() = delete;
    std::variant<std::list<BoundsRemapping>, std::list<BoundsSpec>> u;
  };
  template <typename... Ts, typename = common::NoLvalue<Ts...>> PointerAssignmentStmt(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; PointerAssignmentStmt(PointerAssignmentStmt &&) = default; PointerAssignmentStmt &operator=(PointerAssignmentStmt &&) = default; PointerAssignmentStmt(const PointerAssignmentStmt &) = delete; PointerAssignmentStmt &operator=(const PointerAssignmentStmt &) = delete; PointerAssignmentStmt() = delete;
  mutable AssignmentStmt::TypedAssignment typedAssignment;
  std::tuple<DataRef, Bounds, Expr> t;
};




struct WhereStmt {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> WhereStmt(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; WhereStmt(WhereStmt &&) = default; WhereStmt &operator=(WhereStmt &&) = default; WhereStmt(const WhereStmt &) = delete; WhereStmt &operator=(const WhereStmt &) = delete; WhereStmt() = delete;
  std::tuple<LogicalExpr, AssignmentStmt> t;
};


struct WhereConstructStmt {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> WhereConstructStmt(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; WhereConstructStmt(WhereConstructStmt &&) = default; WhereConstructStmt &operator=(WhereConstructStmt &&) = default; WhereConstructStmt(const WhereConstructStmt &) = delete; WhereConstructStmt &operator=(const WhereConstructStmt &) = delete; WhereConstructStmt() = delete;
  std::tuple<std::optional<Name>, LogicalExpr> t;
};



struct WhereBodyConstruct {
  template <typename A, typename = common::NoLvalue<A>> WhereBodyConstruct(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; WhereBodyConstruct(WhereBodyConstruct &&) = default; WhereBodyConstruct &operator=(WhereBodyConstruct &&) = default; WhereBodyConstruct(const WhereBodyConstruct &) = delete; WhereBodyConstruct &operator=(const WhereBodyConstruct &) = delete; WhereBodyConstruct() = delete;
  std::variant<Statement<AssignmentStmt>, Statement<WhereStmt>,
      common::Indirection<WhereConstruct>>
      u;
};



struct MaskedElsewhereStmt {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> MaskedElsewhereStmt(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; MaskedElsewhereStmt(MaskedElsewhereStmt &&) = default; MaskedElsewhereStmt &operator=(MaskedElsewhereStmt &&) = default; MaskedElsewhereStmt(const MaskedElsewhereStmt &) = delete; MaskedElsewhereStmt &operator=(const MaskedElsewhereStmt &) = delete; MaskedElsewhereStmt() = delete;
  std::tuple<LogicalExpr, std::optional<Name>> t;
};


struct ElsewhereStmt { ElsewhereStmt(ElsewhereStmt &&) = default; ElsewhereStmt &operator=(ElsewhereStmt &&) = default; ElsewhereStmt(const ElsewhereStmt &) = delete; ElsewhereStmt &operator=(const ElsewhereStmt &) = delete; ElsewhereStmt() = delete; ElsewhereStmt(std::optional<Name> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::optional<Name> v; };


struct EndWhereStmt { EndWhereStmt(EndWhereStmt &&) = default; EndWhereStmt &operator=(EndWhereStmt &&) = default; EndWhereStmt(const EndWhereStmt &) = delete; EndWhereStmt &operator=(const EndWhereStmt &) = delete; EndWhereStmt() = delete; EndWhereStmt(std::optional<Name> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::optional<Name> v; };





struct WhereConstruct {
  struct MaskedElsewhere {
    template <typename... Ts, typename = common::NoLvalue<Ts...>> MaskedElsewhere(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; MaskedElsewhere(MaskedElsewhere &&) = default; MaskedElsewhere &operator=(MaskedElsewhere &&) = default; MaskedElsewhere(const MaskedElsewhere &) = delete; MaskedElsewhere &operator=(const MaskedElsewhere &) = delete; MaskedElsewhere() = delete;
    std::tuple<Statement<MaskedElsewhereStmt>, std::list<WhereBodyConstruct>> t;
  };
  struct Elsewhere {
    template <typename... Ts, typename = common::NoLvalue<Ts...>> Elsewhere(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; Elsewhere(Elsewhere &&) = default; Elsewhere &operator=(Elsewhere &&) = default; Elsewhere(const Elsewhere &) = delete; Elsewhere &operator=(const Elsewhere &) = delete; Elsewhere() = delete;
    std::tuple<Statement<ElsewhereStmt>, std::list<WhereBodyConstruct>> t;
  };
  template <typename... Ts, typename = common::NoLvalue<Ts...>> WhereConstruct(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; WhereConstruct(WhereConstruct &&) = default; WhereConstruct &operator=(WhereConstruct &&) = default; WhereConstruct(const WhereConstruct &) = delete; WhereConstruct &operator=(const WhereConstruct &) = delete; WhereConstruct() = delete;
  std::tuple<Statement<WhereConstructStmt>, std::list<WhereBodyConstruct>,
      std::list<MaskedElsewhere>, std::optional<Elsewhere>,
      Statement<EndWhereStmt>>
      t;
};



struct ForallConstructStmt {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> ForallConstructStmt(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; ForallConstructStmt(ForallConstructStmt &&) = default; ForallConstructStmt &operator=(ForallConstructStmt &&) = default; ForallConstructStmt(const ForallConstructStmt &) = delete; ForallConstructStmt &operator=(const ForallConstructStmt &) = delete; ForallConstructStmt() = delete;
  std::tuple<std::optional<Name>, common::Indirection<ConcurrentHeader>> t;
};


struct ForallAssignmentStmt {
  template <typename A, typename = common::NoLvalue<A>> ForallAssignmentStmt(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; ForallAssignmentStmt(ForallAssignmentStmt &&) = default; ForallAssignmentStmt &operator=(ForallAssignmentStmt &&) = default; ForallAssignmentStmt(const ForallAssignmentStmt &) = delete; ForallAssignmentStmt &operator=(const ForallAssignmentStmt &) = delete; ForallAssignmentStmt() = delete;
  std::variant<AssignmentStmt, PointerAssignmentStmt> u;
};


struct ForallStmt {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> ForallStmt(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; ForallStmt(ForallStmt &&) = default; ForallStmt &operator=(ForallStmt &&) = default; ForallStmt(const ForallStmt &) = delete; ForallStmt &operator=(const ForallStmt &) = delete; ForallStmt() = delete;
  std::tuple<common::Indirection<ConcurrentHeader>,
      UnlabeledStatement<ForallAssignmentStmt>>
      t;
};




struct ForallBodyConstruct {
  template <typename A, typename = common::NoLvalue<A>> ForallBodyConstruct(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; ForallBodyConstruct(ForallBodyConstruct &&) = default; ForallBodyConstruct &operator=(ForallBodyConstruct &&) = default; ForallBodyConstruct(const ForallBodyConstruct &) = delete; ForallBodyConstruct &operator=(const ForallBodyConstruct &) = delete; ForallBodyConstruct() = delete;
  std::variant<Statement<ForallAssignmentStmt>, Statement<WhereStmt>,
      WhereConstruct, common::Indirection<ForallConstruct>,
      Statement<ForallStmt>>
      u;
};


struct EndForallStmt { EndForallStmt(EndForallStmt &&) = default; EndForallStmt &operator=(EndForallStmt &&) = default; EndForallStmt(const EndForallStmt &) = delete; EndForallStmt &operator=(const EndForallStmt &) = delete; EndForallStmt() = delete; EndForallStmt(std::optional<Name> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::optional<Name> v; };



struct ForallConstruct {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> ForallConstruct(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; ForallConstruct(ForallConstruct &&) = default; ForallConstruct &operator=(ForallConstruct &&) = default; ForallConstruct(const ForallConstruct &) = delete; ForallConstruct &operator=(const ForallConstruct &) = delete; ForallConstruct() = delete;
  std::tuple<Statement<ForallConstructStmt>, std::list<ForallBodyConstruct>,
      Statement<EndForallStmt>>
      t;
};


using Block = std::list<ExecutionPartConstruct>;


struct Selector {
  template <typename A, typename = common::NoLvalue<A>> Selector(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; Selector(Selector &&) = default; Selector &operator=(Selector &&) = default; Selector(const Selector &) = delete; Selector &operator=(const Selector &) = delete; Selector() = delete;
  std::variant<Expr, Variable> u;
};


struct Association {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> Association(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; Association(Association &&) = default; Association &operator=(Association &&) = default; Association(const Association &) = delete; Association &operator=(const Association &) = delete; Association() = delete;
  std::tuple<Name, Selector> t;
};



struct AssociateStmt {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> AssociateStmt(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; AssociateStmt(AssociateStmt &&) = default; AssociateStmt &operator=(AssociateStmt &&) = default; AssociateStmt(const AssociateStmt &) = delete; AssociateStmt &operator=(const AssociateStmt &) = delete; AssociateStmt() = delete;
  std::tuple<std::optional<Name>, std::list<Association>> t;
};


struct EndAssociateStmt { EndAssociateStmt(EndAssociateStmt &&) = default; EndAssociateStmt &operator=(EndAssociateStmt &&) = default; EndAssociateStmt(const EndAssociateStmt &) = delete; EndAssociateStmt &operator=(const EndAssociateStmt &) = delete; EndAssociateStmt() = delete; EndAssociateStmt(std::optional<Name> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::optional<Name> v; };


struct AssociateConstruct {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> AssociateConstruct(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; AssociateConstruct(AssociateConstruct &&) = default; AssociateConstruct &operator=(AssociateConstruct &&) = default; AssociateConstruct(const AssociateConstruct &) = delete; AssociateConstruct &operator=(const AssociateConstruct &) = delete; AssociateConstruct() = delete;
  std::tuple<Statement<AssociateStmt>, Block, Statement<EndAssociateStmt>> t;
};


struct BlockStmt { BlockStmt(BlockStmt &&) = default; BlockStmt &operator=(BlockStmt &&) = default; BlockStmt(const BlockStmt &) = delete; BlockStmt &operator=(const BlockStmt &) = delete; BlockStmt() = delete; BlockStmt(std::optional<Name> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::optional<Name> v; };


struct EndBlockStmt { EndBlockStmt(EndBlockStmt &&) = default; EndBlockStmt &operator=(EndBlockStmt &&) = default; EndBlockStmt(const EndBlockStmt &) = delete; EndBlockStmt &operator=(const EndBlockStmt &) = delete; EndBlockStmt() = delete; EndBlockStmt(std::optional<Name> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::optional<Name> v; };




struct BlockSpecificationPart { BlockSpecificationPart(BlockSpecificationPart &&) = default; BlockSpecificationPart &operator=(BlockSpecificationPart &&) = default; BlockSpecificationPart(const BlockSpecificationPart &) = delete; BlockSpecificationPart &operator=(const BlockSpecificationPart &) = delete; BlockSpecificationPart() = delete; BlockSpecificationPart(SpecificationPart &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; SpecificationPart v; };







struct BlockConstruct {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> BlockConstruct(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; BlockConstruct(BlockConstruct &&) = default; BlockConstruct &operator=(BlockConstruct &&) = default; BlockConstruct(const BlockConstruct &) = delete; BlockConstruct &operator=(const BlockConstruct &) = delete; BlockConstruct() = delete;
  std::tuple<Statement<BlockStmt>, BlockSpecificationPart, Block,
      Statement<EndBlockStmt>>
      t;
};


struct CoarrayAssociation {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> CoarrayAssociation(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; CoarrayAssociation(CoarrayAssociation &&) = default; CoarrayAssociation &operator=(CoarrayAssociation &&) = default; CoarrayAssociation(const CoarrayAssociation &) = delete; CoarrayAssociation &operator=(const CoarrayAssociation &) = delete; CoarrayAssociation() = delete;
  std::tuple<CodimensionDecl, Selector> t;
};




struct ChangeTeamStmt {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> ChangeTeamStmt(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; ChangeTeamStmt(ChangeTeamStmt &&) = default; ChangeTeamStmt &operator=(ChangeTeamStmt &&) = default; ChangeTeamStmt(const ChangeTeamStmt &) = delete; ChangeTeamStmt &operator=(const ChangeTeamStmt &) = delete; ChangeTeamStmt() = delete;
  std::tuple<std::optional<Name>, TeamValue, std::list<CoarrayAssociation>,
      std::list<StatOrErrmsg>>
      t;
};



struct EndChangeTeamStmt {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> EndChangeTeamStmt(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; EndChangeTeamStmt(EndChangeTeamStmt &&) = default; EndChangeTeamStmt &operator=(EndChangeTeamStmt &&) = default; EndChangeTeamStmt(const EndChangeTeamStmt &) = delete; EndChangeTeamStmt &operator=(const EndChangeTeamStmt &) = delete; EndChangeTeamStmt() = delete;
  std::tuple<std::list<StatOrErrmsg>, std::optional<Name>> t;
};


struct ChangeTeamConstruct {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> ChangeTeamConstruct(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; ChangeTeamConstruct(ChangeTeamConstruct &&) = default; ChangeTeamConstruct &operator=(ChangeTeamConstruct &&) = default; ChangeTeamConstruct(const ChangeTeamConstruct &) = delete; ChangeTeamConstruct &operator=(const ChangeTeamConstruct &) = delete; ChangeTeamConstruct() = delete;
  std::tuple<Statement<ChangeTeamStmt>, Block, Statement<EndChangeTeamStmt>> t;
};



struct CriticalStmt {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> CriticalStmt(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; CriticalStmt(CriticalStmt &&) = default; CriticalStmt &operator=(CriticalStmt &&) = default; CriticalStmt(const CriticalStmt &) = delete; CriticalStmt &operator=(const CriticalStmt &) = delete; CriticalStmt() = delete;
  std::tuple<std::optional<Name>, std::list<StatOrErrmsg>> t;
};


struct EndCriticalStmt { EndCriticalStmt(EndCriticalStmt &&) = default; EndCriticalStmt &operator=(EndCriticalStmt &&) = default; EndCriticalStmt(const EndCriticalStmt &) = delete; EndCriticalStmt &operator=(const EndCriticalStmt &) = delete; EndCriticalStmt() = delete; EndCriticalStmt(std::optional<Name> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::optional<Name> v; };


struct CriticalConstruct {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> CriticalConstruct(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; CriticalConstruct(CriticalConstruct &&) = default; CriticalConstruct &operator=(CriticalConstruct &&) = default; CriticalConstruct(const CriticalConstruct &) = delete; CriticalConstruct &operator=(const CriticalConstruct &) = delete; CriticalConstruct() = delete;
  std::tuple<Statement<CriticalStmt>, Block, Statement<EndCriticalStmt>> t;
};





struct ConcurrentControl {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> ConcurrentControl(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; ConcurrentControl(ConcurrentControl &&) = default; ConcurrentControl &operator=(ConcurrentControl &&) = default; ConcurrentControl(const ConcurrentControl &) = delete; ConcurrentControl &operator=(const ConcurrentControl &) = delete; ConcurrentControl() = delete;
  std::tuple<Name, ScalarIntExpr, ScalarIntExpr, std::optional<ScalarIntExpr>>
      t;
};




struct ConcurrentHeader {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> ConcurrentHeader(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; ConcurrentHeader(ConcurrentHeader &&) = default; ConcurrentHeader &operator=(ConcurrentHeader &&) = default; ConcurrentHeader(const ConcurrentHeader &) = delete; ConcurrentHeader &operator=(const ConcurrentHeader &) = delete; ConcurrentHeader() = delete;
  std::tuple<std::optional<IntegerTypeSpec>, std::list<ConcurrentControl>,
      std::optional<ScalarLogicalExpr>>
      t;
};




struct LocalitySpec {
  template <typename A, typename = common::NoLvalue<A>> LocalitySpec(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; LocalitySpec(LocalitySpec &&) = default; LocalitySpec &operator=(LocalitySpec &&) = default; LocalitySpec(const LocalitySpec &) = delete; LocalitySpec &operator=(const LocalitySpec &) = delete; LocalitySpec() = delete;
  struct Local { Local(Local &&) = default; Local &operator=(Local &&) = default; Local(const Local &) = delete; Local &operator=(const Local &) = delete; Local() = delete; Local(std::list<Name> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::list<Name> v; };
  struct LocalInit { LocalInit(LocalInit &&) = default; LocalInit &operator=(LocalInit &&) = default; LocalInit(const LocalInit &) = delete; LocalInit &operator=(const LocalInit &) = delete; LocalInit() = delete; LocalInit(std::list<Name> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::list<Name> v; };
  struct Shared { Shared(Shared &&) = default; Shared &operator=(Shared &&) = default; Shared(const Shared &) = delete; Shared &operator=(const Shared &) = delete; Shared() = delete; Shared(std::list<Name> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::list<Name> v; };
  struct DefaultNone { DefaultNone() {} DefaultNone(const DefaultNone &) {} DefaultNone(DefaultNone &&) {} DefaultNone &operator=(const DefaultNone &) { return *this; }; DefaultNone &operator=(DefaultNone &&) { return *this; }; using EmptyTrait = std::true_type; };
  std::variant<Local, LocalInit, Shared, DefaultNone> u;
};







struct LoopControl {
  template <typename A, typename = common::NoLvalue<A>> LoopControl(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; LoopControl(LoopControl &&) = default; LoopControl &operator=(LoopControl &&) = default; LoopControl(const LoopControl &) = delete; LoopControl &operator=(const LoopControl &) = delete; LoopControl() = delete;
  struct Concurrent {
    template <typename... Ts, typename = common::NoLvalue<Ts...>> Concurrent(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; Concurrent(Concurrent &&) = default; Concurrent &operator=(Concurrent &&) = default; Concurrent(const Concurrent &) = delete; Concurrent &operator=(const Concurrent &) = delete; Concurrent() = delete;
    std::tuple<ConcurrentHeader, std::list<LocalitySpec>> t;
  };
  using Bounds = LoopBounds<ScalarName, ScalarExpr>;
  std::variant<Bounds, ScalarLogicalExpr, Concurrent> u;
};


struct LabelDoStmt {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> LabelDoStmt(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; LabelDoStmt(LabelDoStmt &&) = default; LabelDoStmt &operator=(LabelDoStmt &&) = default; LabelDoStmt(const LabelDoStmt &) = delete; LabelDoStmt &operator=(const LabelDoStmt &) = delete; LabelDoStmt() = delete;
  std::tuple<std::optional<Name>, Label, std::optional<LoopControl>> t;
};


struct NonLabelDoStmt {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> NonLabelDoStmt(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; NonLabelDoStmt(NonLabelDoStmt &&) = default; NonLabelDoStmt &operator=(NonLabelDoStmt &&) = default; NonLabelDoStmt(const NonLabelDoStmt &) = delete; NonLabelDoStmt &operator=(const NonLabelDoStmt &) = delete; NonLabelDoStmt() = delete;
  std::tuple<std::optional<Name>, std::optional<LoopControl>> t;
};


struct EndDoStmt { EndDoStmt(EndDoStmt &&) = default; EndDoStmt &operator=(EndDoStmt &&) = default; EndDoStmt(const EndDoStmt &) = delete; EndDoStmt &operator=(const EndDoStmt &) = delete; EndDoStmt() = delete; EndDoStmt(std::optional<Name> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::optional<Name> v; };







struct DoConstruct {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> DoConstruct(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; DoConstruct(DoConstruct &&) = default; DoConstruct &operator=(DoConstruct &&) = default; DoConstruct(const DoConstruct &) = delete; DoConstruct &operator=(const DoConstruct &) = delete; DoConstruct() = delete;
  const std::optional<LoopControl> &GetLoopControl() const;
  bool IsDoNormal() const;
  bool IsDoWhile() const;
  bool IsDoConcurrent() const;
  std::tuple<Statement<NonLabelDoStmt>, Block, Statement<EndDoStmt>> t;
};


struct CycleStmt { CycleStmt(CycleStmt &&) = default; CycleStmt &operator=(CycleStmt &&) = default; CycleStmt(const CycleStmt &) = delete; CycleStmt &operator=(const CycleStmt &) = delete; CycleStmt() = delete; CycleStmt(std::optional<Name> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::optional<Name> v; };


struct IfThenStmt {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> IfThenStmt(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; IfThenStmt(IfThenStmt &&) = default; IfThenStmt &operator=(IfThenStmt &&) = default; IfThenStmt(const IfThenStmt &) = delete; IfThenStmt &operator=(const IfThenStmt &) = delete; IfThenStmt() = delete;
  std::tuple<std::optional<Name>, ScalarLogicalExpr> t;
};



struct ElseIfStmt {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> ElseIfStmt(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; ElseIfStmt(ElseIfStmt &&) = default; ElseIfStmt &operator=(ElseIfStmt &&) = default; ElseIfStmt(const ElseIfStmt &) = delete; ElseIfStmt &operator=(const ElseIfStmt &) = delete; ElseIfStmt() = delete;
  std::tuple<ScalarLogicalExpr, std::optional<Name>> t;
};


struct ElseStmt { ElseStmt(ElseStmt &&) = default; ElseStmt &operator=(ElseStmt &&) = default; ElseStmt(const ElseStmt &) = delete; ElseStmt &operator=(const ElseStmt &) = delete; ElseStmt() = delete; ElseStmt(std::optional<Name> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::optional<Name> v; };


struct EndIfStmt { EndIfStmt(EndIfStmt &&) = default; EndIfStmt &operator=(EndIfStmt &&) = default; EndIfStmt(const EndIfStmt &) = delete; EndIfStmt &operator=(const EndIfStmt &) = delete; EndIfStmt() = delete; EndIfStmt(std::optional<Name> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::optional<Name> v; };




struct IfConstruct {
  struct ElseIfBlock {
    template <typename... Ts, typename = common::NoLvalue<Ts...>> ElseIfBlock(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; ElseIfBlock(ElseIfBlock &&) = default; ElseIfBlock &operator=(ElseIfBlock &&) = default; ElseIfBlock(const ElseIfBlock &) = delete; ElseIfBlock &operator=(const ElseIfBlock &) = delete; ElseIfBlock() = delete;
    std::tuple<Statement<ElseIfStmt>, Block> t;
  };
  struct ElseBlock {
    template <typename... Ts, typename = common::NoLvalue<Ts...>> ElseBlock(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; ElseBlock(ElseBlock &&) = default; ElseBlock &operator=(ElseBlock &&) = default; ElseBlock(const ElseBlock &) = delete; ElseBlock &operator=(const ElseBlock &) = delete; ElseBlock() = delete;
    std::tuple<Statement<ElseStmt>, Block> t;
  };
  template <typename... Ts, typename = common::NoLvalue<Ts...>> IfConstruct(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; IfConstruct(IfConstruct &&) = default; IfConstruct &operator=(IfConstruct &&) = default; IfConstruct(const IfConstruct &) = delete; IfConstruct &operator=(const IfConstruct &) = delete; IfConstruct() = delete;
  std::tuple<Statement<IfThenStmt>, Block, std::list<ElseIfBlock>,
      std::optional<ElseBlock>, Statement<EndIfStmt>>
      t;
};


struct IfStmt {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> IfStmt(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; IfStmt(IfStmt &&) = default; IfStmt &operator=(IfStmt &&) = default; IfStmt(const IfStmt &) = delete; IfStmt &operator=(const IfStmt &) = delete; IfStmt() = delete;
  std::tuple<ScalarLogicalExpr, UnlabeledStatement<ActionStmt>> t;
};



struct SelectCaseStmt {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> SelectCaseStmt(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; SelectCaseStmt(SelectCaseStmt &&) = default; SelectCaseStmt &operator=(SelectCaseStmt &&) = default; SelectCaseStmt(const SelectCaseStmt &) = delete; SelectCaseStmt &operator=(const SelectCaseStmt &) = delete; SelectCaseStmt() = delete;
  std::tuple<std::optional<Name>, Scalar<Expr>> t;
};


using CaseValue = Scalar<ConstantExpr>;



struct CaseValueRange {
  template <typename A, typename = common::NoLvalue<A>> CaseValueRange(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; CaseValueRange(CaseValueRange &&) = default; CaseValueRange &operator=(CaseValueRange &&) = default; CaseValueRange(const CaseValueRange &) = delete; CaseValueRange &operator=(const CaseValueRange &) = delete; CaseValueRange() = delete;
  struct Range {
    Range(Range &&) = default; Range &operator=(Range &&) = default; Range(const Range &) = delete; Range &operator=(const Range &) = delete; Range() = delete;
    Range(std::optional<CaseValue> &&l, std::optional<CaseValue> &&u)
        : lower{std::move(l)}, upper{std::move(u)} {}
    std::optional<CaseValue> lower, upper;
  };
  std::variant<CaseValue, Range> u;
};


struct Default { Default() {} Default(const Default &) {} Default(Default &&) {} Default &operator=(const Default &) { return *this; }; Default &operator=(Default &&) { return *this; }; using EmptyTrait = std::true_type; };

struct CaseSelector {
  template <typename A, typename = common::NoLvalue<A>> CaseSelector(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; CaseSelector(CaseSelector &&) = default; CaseSelector &operator=(CaseSelector &&) = default; CaseSelector(const CaseSelector &) = delete; CaseSelector &operator=(const CaseSelector &) = delete; CaseSelector() = delete;
  std::variant<std::list<CaseValueRange>, Default> u;
};


struct CaseStmt {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> CaseStmt(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; CaseStmt(CaseStmt &&) = default; CaseStmt &operator=(CaseStmt &&) = default; CaseStmt(const CaseStmt &) = delete; CaseStmt &operator=(const CaseStmt &) = delete; CaseStmt() = delete;
  std::tuple<CaseSelector, std::optional<Name>> t;
};




struct EndSelectStmt { EndSelectStmt(EndSelectStmt &&) = default; EndSelectStmt &operator=(EndSelectStmt &&) = default; EndSelectStmt(const EndSelectStmt &) = delete; EndSelectStmt &operator=(const EndSelectStmt &) = delete; EndSelectStmt() = delete; EndSelectStmt(std::optional<Name> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::optional<Name> v; };



struct CaseConstruct {
  struct Case {
    template <typename... Ts, typename = common::NoLvalue<Ts...>> Case(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; Case(Case &&) = default; Case &operator=(Case &&) = default; Case(const Case &) = delete; Case &operator=(const Case &) = delete; Case() = delete;
    std::tuple<Statement<CaseStmt>, Block> t;
  };
  template <typename... Ts, typename = common::NoLvalue<Ts...>> CaseConstruct(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; CaseConstruct(CaseConstruct &&) = default; CaseConstruct &operator=(CaseConstruct &&) = default; CaseConstruct(const CaseConstruct &) = delete; CaseConstruct &operator=(const CaseConstruct &) = delete; CaseConstruct() = delete;
  std::tuple<Statement<SelectCaseStmt>, std::list<Case>,
      Statement<EndSelectStmt>>
      t;
};




struct SelectRankStmt {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> SelectRankStmt(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; SelectRankStmt(SelectRankStmt &&) = default; SelectRankStmt &operator=(SelectRankStmt &&) = default; SelectRankStmt(const SelectRankStmt &) = delete; SelectRankStmt &operator=(const SelectRankStmt &) = delete; SelectRankStmt() = delete;
  std::tuple<std::optional<Name>, std::optional<Name>, Selector> t;
};





struct SelectRankCaseStmt {
  struct Rank {
    template <typename A, typename = common::NoLvalue<A>> Rank(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; Rank(Rank &&) = default; Rank &operator=(Rank &&) = default; Rank(const Rank &) = delete; Rank &operator=(const Rank &) = delete; Rank() = delete;
    std::variant<ScalarIntConstantExpr, Star, Default> u;
  };
  template <typename... Ts, typename = common::NoLvalue<Ts...>> SelectRankCaseStmt(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; SelectRankCaseStmt(SelectRankCaseStmt &&) = default; SelectRankCaseStmt &operator=(SelectRankCaseStmt &&) = default; SelectRankCaseStmt(const SelectRankCaseStmt &) = delete; SelectRankCaseStmt &operator=(const SelectRankCaseStmt &) = delete; SelectRankCaseStmt() = delete;
  std::tuple<Rank, std::optional<Name>> t;
};




struct SelectRankConstruct {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> SelectRankConstruct(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; SelectRankConstruct(SelectRankConstruct &&) = default; SelectRankConstruct &operator=(SelectRankConstruct &&) = default; SelectRankConstruct(const SelectRankConstruct &) = delete; SelectRankConstruct &operator=(const SelectRankConstruct &) = delete; SelectRankConstruct() = delete;
  struct RankCase {
    template <typename... Ts, typename = common::NoLvalue<Ts...>> RankCase(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; RankCase(RankCase &&) = default; RankCase &operator=(RankCase &&) = default; RankCase(const RankCase &) = delete; RankCase &operator=(const RankCase &) = delete; RankCase() = delete;
    std::tuple<Statement<SelectRankCaseStmt>, Block> t;
  };
  std::tuple<Statement<SelectRankStmt>, std::list<RankCase>,
      Statement<EndSelectStmt>>
      t;
};




struct SelectTypeStmt {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> SelectTypeStmt(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; SelectTypeStmt(SelectTypeStmt &&) = default; SelectTypeStmt &operator=(SelectTypeStmt &&) = default; SelectTypeStmt(const SelectTypeStmt &) = delete; SelectTypeStmt &operator=(const SelectTypeStmt &) = delete; SelectTypeStmt() = delete;
  std::tuple<std::optional<Name>, std::optional<Name>, Selector> t;
};





struct TypeGuardStmt {
  struct Guard {
    template <typename A, typename = common::NoLvalue<A>> Guard(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; Guard(Guard &&) = default; Guard &operator=(Guard &&) = default; Guard(const Guard &) = delete; Guard &operator=(const Guard &) = delete; Guard() = delete;
    std::variant<TypeSpec, DerivedTypeSpec, Default> u;
  };
  template <typename... Ts, typename = common::NoLvalue<Ts...>> TypeGuardStmt(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; TypeGuardStmt(TypeGuardStmt &&) = default; TypeGuardStmt &operator=(TypeGuardStmt &&) = default; TypeGuardStmt(const TypeGuardStmt &) = delete; TypeGuardStmt &operator=(const TypeGuardStmt &) = delete; TypeGuardStmt() = delete;
  std::tuple<Guard, std::optional<Name>> t;
};



struct SelectTypeConstruct {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> SelectTypeConstruct(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; SelectTypeConstruct(SelectTypeConstruct &&) = default; SelectTypeConstruct &operator=(SelectTypeConstruct &&) = default; SelectTypeConstruct(const SelectTypeConstruct &) = delete; SelectTypeConstruct &operator=(const SelectTypeConstruct &) = delete; SelectTypeConstruct() = delete;
  struct TypeCase {
    template <typename... Ts, typename = common::NoLvalue<Ts...>> TypeCase(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; TypeCase(TypeCase &&) = default; TypeCase &operator=(TypeCase &&) = default; TypeCase(const TypeCase &) = delete; TypeCase &operator=(const TypeCase &) = delete; TypeCase() = delete;
    std::tuple<Statement<TypeGuardStmt>, Block> t;
  };
  std::tuple<Statement<SelectTypeStmt>, std::list<TypeCase>,
      Statement<EndSelectStmt>>
      t;
};


struct ExitStmt { ExitStmt(ExitStmt &&) = default; ExitStmt &operator=(ExitStmt &&) = default; ExitStmt(const ExitStmt &) = delete; ExitStmt &operator=(const ExitStmt &) = delete; ExitStmt() = delete; ExitStmt(std::optional<Name> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::optional<Name> v; };


struct GotoStmt { GotoStmt(GotoStmt &&) = default; GotoStmt &operator=(GotoStmt &&) = default; GotoStmt(const GotoStmt &) = delete; GotoStmt &operator=(const GotoStmt &) = delete; GotoStmt() = delete; GotoStmt(Label &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; Label v; };


struct ComputedGotoStmt {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> ComputedGotoStmt(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; ComputedGotoStmt(ComputedGotoStmt &&) = default; ComputedGotoStmt &operator=(ComputedGotoStmt &&) = default; ComputedGotoStmt(const ComputedGotoStmt &) = delete; ComputedGotoStmt &operator=(const ComputedGotoStmt &) = delete; ComputedGotoStmt() = delete;
  std::tuple<std::list<Label>, ScalarIntExpr> t;
};





struct StopCode { StopCode(StopCode &&) = default; StopCode &operator=(StopCode &&) = default; StopCode(const StopCode &) = delete; StopCode &operator=(const StopCode &) = delete; StopCode() = delete; StopCode(Scalar<Expr> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; Scalar<Expr> v; };




struct StopStmt {
  ENUM_CLASS(Kind, Stop, ErrorStop)
  template <typename... Ts, typename = common::NoLvalue<Ts...>> StopStmt(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; StopStmt(StopStmt &&) = default; StopStmt &operator=(StopStmt &&) = default; StopStmt(const StopStmt &) = delete; StopStmt &operator=(const StopStmt &) = delete; StopStmt() = delete;
  std::tuple<Kind, std::optional<StopCode>, std::optional<ScalarLogicalExpr>> t;
};


struct SyncAllStmt { SyncAllStmt(SyncAllStmt &&) = default; SyncAllStmt &operator=(SyncAllStmt &&) = default; SyncAllStmt(const SyncAllStmt &) = delete; SyncAllStmt &operator=(const SyncAllStmt &) = delete; SyncAllStmt() = delete; SyncAllStmt(std::list<StatOrErrmsg> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::list<StatOrErrmsg> v; };



struct SyncImagesStmt {
  struct ImageSet {
    template <typename A, typename = common::NoLvalue<A>> ImageSet(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; ImageSet(ImageSet &&) = default; ImageSet &operator=(ImageSet &&) = default; ImageSet(const ImageSet &) = delete; ImageSet &operator=(const ImageSet &) = delete; ImageSet() = delete;
    std::variant<IntExpr, Star> u;
  };
  template <typename... Ts, typename = common::NoLvalue<Ts...>> SyncImagesStmt(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; SyncImagesStmt(SyncImagesStmt &&) = default; SyncImagesStmt &operator=(SyncImagesStmt &&) = default; SyncImagesStmt(const SyncImagesStmt &) = delete; SyncImagesStmt &operator=(const SyncImagesStmt &) = delete; SyncImagesStmt() = delete;
  std::tuple<ImageSet, std::list<StatOrErrmsg>> t;
};


struct SyncMemoryStmt { SyncMemoryStmt(SyncMemoryStmt &&) = default; SyncMemoryStmt &operator=(SyncMemoryStmt &&) = default; SyncMemoryStmt(const SyncMemoryStmt &) = delete; SyncMemoryStmt &operator=(const SyncMemoryStmt &) = delete; SyncMemoryStmt() = delete; SyncMemoryStmt(std::list<StatOrErrmsg> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::list<StatOrErrmsg> v; };


struct SyncTeamStmt {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> SyncTeamStmt(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; SyncTeamStmt(SyncTeamStmt &&) = default; SyncTeamStmt &operator=(SyncTeamStmt &&) = default; SyncTeamStmt(const SyncTeamStmt &) = delete; SyncTeamStmt &operator=(const SyncTeamStmt &) = delete; SyncTeamStmt() = delete;
  std::tuple<TeamValue, std::list<StatOrErrmsg>> t;
};


using EventVariable = Scalar<Variable>;


struct EventPostStmt {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> EventPostStmt(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; EventPostStmt(EventPostStmt &&) = default; EventPostStmt &operator=(EventPostStmt &&) = default; EventPostStmt(const EventPostStmt &) = delete; EventPostStmt &operator=(const EventPostStmt &) = delete; EventPostStmt() = delete;
  std::tuple<EventVariable, std::list<StatOrErrmsg>> t;
};





struct EventWaitStmt {
  struct EventWaitSpec {
    template <typename A, typename = common::NoLvalue<A>> EventWaitSpec(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; EventWaitSpec(EventWaitSpec &&) = default; EventWaitSpec &operator=(EventWaitSpec &&) = default; EventWaitSpec(const EventWaitSpec &) = delete; EventWaitSpec &operator=(const EventWaitSpec &) = delete; EventWaitSpec() = delete;
    std::variant<ScalarIntExpr, StatOrErrmsg> u;
  };
  template <typename... Ts, typename = common::NoLvalue<Ts...>> EventWaitStmt(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; EventWaitStmt(EventWaitStmt &&) = default; EventWaitStmt &operator=(EventWaitStmt &&) = default; EventWaitStmt(const EventWaitStmt &) = delete; EventWaitStmt &operator=(const EventWaitStmt &) = delete; EventWaitStmt() = delete;
  std::tuple<EventVariable, std::list<EventWaitSpec>> t;
};


using TeamVariable = Scalar<Variable>;





struct FormTeamStmt {
  struct FormTeamSpec {
    template <typename A, typename = common::NoLvalue<A>> FormTeamSpec(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; FormTeamSpec(FormTeamSpec &&) = default; FormTeamSpec &operator=(FormTeamSpec &&) = default; FormTeamSpec(const FormTeamSpec &) = delete; FormTeamSpec &operator=(const FormTeamSpec &) = delete; FormTeamSpec() = delete;
    std::variant<ScalarIntExpr, StatOrErrmsg> u;
  };
  template <typename... Ts, typename = common::NoLvalue<Ts...>> FormTeamStmt(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; FormTeamStmt(FormTeamStmt &&) = default; FormTeamStmt &operator=(FormTeamStmt &&) = default; FormTeamStmt(const FormTeamStmt &) = delete; FormTeamStmt &operator=(const FormTeamStmt &) = delete; FormTeamStmt() = delete;
  std::tuple<ScalarIntExpr, TeamVariable, std::list<FormTeamSpec>> t;
};


using LockVariable = Scalar<Variable>;



struct LockStmt {
  struct LockStat {
    template <typename A, typename = common::NoLvalue<A>> LockStat(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; LockStat(LockStat &&) = default; LockStat &operator=(LockStat &&) = default; LockStat(const LockStat &) = delete; LockStat &operator=(const LockStat &) = delete; LockStat() = delete;
    std::variant<Scalar<Logical<Variable>>, StatOrErrmsg> u;
  };
  template <typename... Ts, typename = common::NoLvalue<Ts...>> LockStmt(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; LockStmt(LockStmt &&) = default; LockStmt &operator=(LockStmt &&) = default; LockStmt(const LockStmt &) = delete; LockStmt &operator=(const LockStmt &) = delete; LockStmt() = delete;
  std::tuple<LockVariable, std::list<LockStat>> t;
};


struct UnlockStmt {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> UnlockStmt(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; UnlockStmt(UnlockStmt &&) = default; UnlockStmt &operator=(UnlockStmt &&) = default; UnlockStmt(const UnlockStmt &) = delete; UnlockStmt &operator=(const UnlockStmt &) = delete; UnlockStmt() = delete;
  std::tuple<LockVariable, std::list<StatOrErrmsg>> t;
};


struct FileUnitNumber { FileUnitNumber(FileUnitNumber &&) = default; FileUnitNumber &operator=(FileUnitNumber &&) = default; FileUnitNumber(const FileUnitNumber &) = delete; FileUnitNumber &operator=(const FileUnitNumber &) = delete; FileUnitNumber() = delete; FileUnitNumber(ScalarIntExpr &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; ScalarIntExpr v; };
# 2507 "temp.h"
struct IoUnit {
  template <typename A, typename = common::NoLvalue<A>> IoUnit(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; IoUnit(IoUnit &&) = default; IoUnit &operator=(IoUnit &&) = default; IoUnit(const IoUnit &) = delete; IoUnit &operator=(const IoUnit &) = delete; IoUnit() = delete;
  std::variant<Variable, FileUnitNumber, Star> u;
};


using FileNameExpr = ScalarDefaultCharExpr;
# 2531 "temp.h"
struct StatusExpr { StatusExpr(StatusExpr &&) = default; StatusExpr &operator=(StatusExpr &&) = default; StatusExpr(const StatusExpr &) = delete; StatusExpr &operator=(const StatusExpr &) = delete; StatusExpr() = delete; StatusExpr(ScalarDefaultCharExpr &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; ScalarDefaultCharExpr v; };
struct ErrLabel { ErrLabel(ErrLabel &&) = default; ErrLabel &operator=(ErrLabel &&) = default; ErrLabel(const ErrLabel &) = delete; ErrLabel &operator=(const ErrLabel &) = delete; ErrLabel() = delete; ErrLabel(Label &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; Label v; };

struct ConnectSpec {
  template <typename A, typename = common::NoLvalue<A>> ConnectSpec(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; ConnectSpec(ConnectSpec &&) = default; ConnectSpec &operator=(ConnectSpec &&) = default; ConnectSpec(const ConnectSpec &) = delete; ConnectSpec &operator=(const ConnectSpec &) = delete; ConnectSpec() = delete;
  struct CharExpr {
    ENUM_CLASS(Kind, Access, Action, Asynchronous, Blank, Decimal, Delim,
        Encoding, Form, Pad, Position, Round, Sign,
                          Convert, Dispose)
    template <typename... Ts, typename = common::NoLvalue<Ts...>> CharExpr(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; CharExpr(CharExpr &&) = default; CharExpr &operator=(CharExpr &&) = default; CharExpr(const CharExpr &) = delete; CharExpr &operator=(const CharExpr &) = delete; CharExpr() = delete;
    std::tuple<Kind, ScalarDefaultCharExpr> t;
  };
  struct Recl { Recl(Recl &&) = default; Recl &operator=(Recl &&) = default; Recl(const Recl &) = delete; Recl &operator=(const Recl &) = delete; Recl() = delete; Recl(ScalarIntExpr &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; ScalarIntExpr v; };
  struct Newunit { Newunit(Newunit &&) = default; Newunit &operator=(Newunit &&) = default; Newunit(const Newunit &) = delete; Newunit &operator=(const Newunit &) = delete; Newunit() = delete; Newunit(ScalarIntVariable &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; ScalarIntVariable v; };
  std::variant<FileUnitNumber, FileNameExpr, CharExpr, MsgVariable,
      StatVariable, Recl, Newunit, ErrLabel, StatusExpr>
      u;
};


struct OpenStmt { OpenStmt(OpenStmt &&) = default; OpenStmt &operator=(OpenStmt &&) = default; OpenStmt(const OpenStmt &) = delete; OpenStmt &operator=(const OpenStmt &) = delete; OpenStmt() = delete; OpenStmt(std::list<ConnectSpec> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::list<ConnectSpec> v; };






struct CloseStmt {
  struct CloseSpec {
    template <typename A, typename = common::NoLvalue<A>> CloseSpec(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; CloseSpec(CloseSpec &&) = default; CloseSpec &operator=(CloseSpec &&) = default; CloseSpec(const CloseSpec &) = delete; CloseSpec &operator=(const CloseSpec &) = delete; CloseSpec() = delete;
    std::variant<FileUnitNumber, StatVariable, MsgVariable, ErrLabel,
        StatusExpr>
        u;
  };
  CloseStmt(CloseStmt &&) = default; CloseStmt &operator=(CloseStmt &&) = default; CloseStmt(const CloseStmt &) = delete; CloseStmt &operator=(const CloseStmt &) = delete; CloseStmt() = delete; CloseStmt(std::list<CloseSpec> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::list<CloseSpec> v;
};



struct Format {
  template <typename A, typename = common::NoLvalue<A>> Format(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; Format(Format &&) = default; Format &operator=(Format &&) = default; Format(const Format &) = delete; Format &operator=(const Format &) = delete; Format() = delete;
  std::variant<Expr, Label, Star> u;
};


struct IdVariable { IdVariable(IdVariable &&) = default; IdVariable &operator=(IdVariable &&) = default; IdVariable(const IdVariable &) = delete; IdVariable &operator=(const IdVariable &) = delete; IdVariable() = delete; IdVariable(ScalarIntVariable &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; ScalarIntVariable v; };
# 2590 "temp.h"
struct EndLabel { EndLabel(EndLabel &&) = default; EndLabel &operator=(EndLabel &&) = default; EndLabel(const EndLabel &) = delete; EndLabel &operator=(const EndLabel &) = delete; EndLabel() = delete; EndLabel(Label &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; Label v; };
struct EorLabel { EorLabel(EorLabel &&) = default; EorLabel &operator=(EorLabel &&) = default; EorLabel(const EorLabel &) = delete; EorLabel &operator=(const EorLabel &) = delete; EorLabel() = delete; EorLabel(Label &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; Label v; };
struct IoControlSpec {
  template <typename A, typename = common::NoLvalue<A>> IoControlSpec(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; IoControlSpec(IoControlSpec &&) = default; IoControlSpec &operator=(IoControlSpec &&) = default; IoControlSpec(const IoControlSpec &) = delete; IoControlSpec &operator=(const IoControlSpec &) = delete; IoControlSpec() = delete;
  struct CharExpr {
    ENUM_CLASS(Kind, Advance, Blank, Decimal, Delim, Pad, Round, Sign)
    template <typename... Ts, typename = common::NoLvalue<Ts...>> CharExpr(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; CharExpr(CharExpr &&) = default; CharExpr &operator=(CharExpr &&) = default; CharExpr(const CharExpr &) = delete; CharExpr &operator=(const CharExpr &) = delete; CharExpr() = delete;
    std::tuple<Kind, ScalarDefaultCharExpr> t;
  };
  struct Asynchronous { Asynchronous(Asynchronous &&) = default; Asynchronous &operator=(Asynchronous &&) = default; Asynchronous(const Asynchronous &) = delete; Asynchronous &operator=(const Asynchronous &) = delete; Asynchronous() = delete; Asynchronous(ScalarDefaultCharConstantExpr &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; ScalarDefaultCharConstantExpr v; };
  struct Pos { Pos(Pos &&) = default; Pos &operator=(Pos &&) = default; Pos(const Pos &) = delete; Pos &operator=(const Pos &) = delete; Pos() = delete; Pos(ScalarIntExpr &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; ScalarIntExpr v; };
  struct Rec { Rec(Rec &&) = default; Rec &operator=(Rec &&) = default; Rec(const Rec &) = delete; Rec &operator=(const Rec &) = delete; Rec() = delete; Rec(ScalarIntExpr &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; ScalarIntExpr v; };
  struct Size { Size(Size &&) = default; Size &operator=(Size &&) = default; Size(const Size &) = delete; Size &operator=(const Size &) = delete; Size() = delete; Size(ScalarIntVariable &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; ScalarIntVariable v; };
  std::variant<IoUnit, Format, Name, CharExpr, Asynchronous, EndLabel, EorLabel,
      ErrLabel, IdVariable, MsgVariable, StatVariable, Pos, Rec, Size>
      u;
};


struct InputItem {
  template <typename A, typename = common::NoLvalue<A>> InputItem(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; InputItem(InputItem &&) = default; InputItem &operator=(InputItem &&) = default; InputItem(const InputItem &) = delete; InputItem &operator=(const InputItem &) = delete; InputItem() = delete;
  std::variant<Variable, common::Indirection<InputImpliedDo>> u;
};




struct ReadStmt {
  ReadStmt(ReadStmt &&) = default; ReadStmt &operator=(ReadStmt &&) = default; ReadStmt(const ReadStmt &) = delete; ReadStmt &operator=(const ReadStmt &) = delete; ReadStmt() = delete;
  ReadStmt(std::optional<IoUnit> &&i, std::optional<Format> &&f,
      std::list<IoControlSpec> &&cs, std::list<InputItem> &&its)
      : iounit{std::move(i)}, format{std::move(f)}, controls(std::move(cs)),
        items(std::move(its)) {}
  std::optional<IoUnit> iounit;

  std::optional<Format> format;


  std::list<IoControlSpec> controls;
  std::list<InputItem> items;
};


struct OutputItem {
  template <typename A, typename = common::NoLvalue<A>> OutputItem(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; OutputItem(OutputItem &&) = default; OutputItem &operator=(OutputItem &&) = default; OutputItem(const OutputItem &) = delete; OutputItem &operator=(const OutputItem &) = delete; OutputItem() = delete;
  std::variant<Expr, common::Indirection<OutputImpliedDo>> u;
};


struct WriteStmt {
  WriteStmt(WriteStmt &&) = default; WriteStmt &operator=(WriteStmt &&) = default; WriteStmt(const WriteStmt &) = delete; WriteStmt &operator=(const WriteStmt &) = delete; WriteStmt() = delete;
  WriteStmt(std::optional<IoUnit> &&i, std::optional<Format> &&f,
      std::list<IoControlSpec> &&cs, std::list<OutputItem> &&its)
      : iounit{std::move(i)}, format{std::move(f)}, controls(std::move(cs)),
        items(std::move(its)) {}
  std::optional<IoUnit> iounit;

  std::optional<Format> format;

  std::list<IoControlSpec> controls;
  std::list<OutputItem> items;
};


struct PrintStmt {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> PrintStmt(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; PrintStmt(PrintStmt &&) = default; PrintStmt &operator=(PrintStmt &&) = default; PrintStmt(const PrintStmt &) = delete; PrintStmt &operator=(const PrintStmt &) = delete; PrintStmt() = delete;
  std::tuple<Format, std::list<OutputItem>> t;
};



using IoImpliedDoControl = LoopBounds<DoVariable, ScalarIntExpr>;



struct InputImpliedDo {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> InputImpliedDo(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; InputImpliedDo(InputImpliedDo &&) = default; InputImpliedDo &operator=(InputImpliedDo &&) = default; InputImpliedDo(const InputImpliedDo &) = delete; InputImpliedDo &operator=(const InputImpliedDo &) = delete; InputImpliedDo() = delete;
  std::tuple<std::list<InputItem>, IoImpliedDoControl> t;
};

struct OutputImpliedDo {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> OutputImpliedDo(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; OutputImpliedDo(OutputImpliedDo &&) = default; OutputImpliedDo &operator=(OutputImpliedDo &&) = default; OutputImpliedDo(const OutputImpliedDo &) = delete; OutputImpliedDo &operator=(const OutputImpliedDo &) = delete; OutputImpliedDo() = delete;
  std::tuple<std::list<OutputItem>, IoImpliedDoControl> t;
};





struct IdExpr { IdExpr(IdExpr &&) = default; IdExpr &operator=(IdExpr &&) = default; IdExpr(const IdExpr &) = delete; IdExpr &operator=(const IdExpr &) = delete; IdExpr() = delete; IdExpr(ScalarIntExpr &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; ScalarIntExpr v; };
struct WaitSpec {
  template <typename A, typename = common::NoLvalue<A>> WaitSpec(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; WaitSpec(WaitSpec &&) = default; WaitSpec &operator=(WaitSpec &&) = default; WaitSpec(const WaitSpec &) = delete; WaitSpec &operator=(const WaitSpec &) = delete; WaitSpec() = delete;
  std::variant<FileUnitNumber, EndLabel, EorLabel, ErrLabel, IdExpr,
      MsgVariable, StatVariable>
      u;
};


struct WaitStmt { WaitStmt(WaitStmt &&) = default; WaitStmt &operator=(WaitStmt &&) = default; WaitStmt(const WaitStmt &) = delete; WaitStmt &operator=(const WaitStmt &) = delete; WaitStmt() = delete; WaitStmt(std::list<WaitSpec> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::list<WaitSpec> v; };







struct PositionOrFlushSpec {
  template <typename A, typename = common::NoLvalue<A>> PositionOrFlushSpec(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; PositionOrFlushSpec(PositionOrFlushSpec &&) = default; PositionOrFlushSpec &operator=(PositionOrFlushSpec &&) = default; PositionOrFlushSpec(const PositionOrFlushSpec &) = delete; PositionOrFlushSpec &operator=(const PositionOrFlushSpec &) = delete; PositionOrFlushSpec() = delete;
  std::variant<FileUnitNumber, MsgVariable, StatVariable, ErrLabel> u;
};



struct BackspaceStmt { BackspaceStmt(BackspaceStmt &&) = default; BackspaceStmt &operator=(BackspaceStmt &&) = default; BackspaceStmt(const BackspaceStmt &) = delete; BackspaceStmt &operator=(const BackspaceStmt &) = delete; BackspaceStmt() = delete; BackspaceStmt(std::list<PositionOrFlushSpec> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::list<PositionOrFlushSpec> v; };



struct EndfileStmt { EndfileStmt(EndfileStmt &&) = default; EndfileStmt &operator=(EndfileStmt &&) = default; EndfileStmt(const EndfileStmt &) = delete; EndfileStmt &operator=(const EndfileStmt &) = delete; EndfileStmt() = delete; EndfileStmt(std::list<PositionOrFlushSpec> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::list<PositionOrFlushSpec> v; };


struct RewindStmt { RewindStmt(RewindStmt &&) = default; RewindStmt &operator=(RewindStmt &&) = default; RewindStmt(const RewindStmt &) = delete; RewindStmt &operator=(const RewindStmt &) = delete; RewindStmt() = delete; RewindStmt(std::list<PositionOrFlushSpec> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::list<PositionOrFlushSpec> v; };


struct FlushStmt { FlushStmt(FlushStmt &&) = default; FlushStmt &operator=(FlushStmt &&) = default; FlushStmt(const FlushStmt &) = delete; FlushStmt &operator=(const FlushStmt &) = delete; FlushStmt() = delete; FlushStmt(std::list<PositionOrFlushSpec> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::list<PositionOrFlushSpec> v; };
# 2749 "temp.h"
struct InquireSpec {
  template <typename A, typename = common::NoLvalue<A>> InquireSpec(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; InquireSpec(InquireSpec &&) = default; InquireSpec &operator=(InquireSpec &&) = default; InquireSpec(const InquireSpec &) = delete; InquireSpec &operator=(const InquireSpec &) = delete; InquireSpec() = delete;
  struct CharVar {
    ENUM_CLASS(Kind, Access, Action, Asynchronous, Blank, Decimal, Delim,
        Direct, Encoding, Form, Formatted, Iomsg, Name, Pad, Position, Read,
        Readwrite, Round, Sequential, Sign, Stream, Status, Unformatted, Write,
                          Convert, Dispose)
    template <typename... Ts, typename = common::NoLvalue<Ts...>> CharVar(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; CharVar(CharVar &&) = default; CharVar &operator=(CharVar &&) = default; CharVar(const CharVar &) = delete; CharVar &operator=(const CharVar &) = delete; CharVar() = delete;
    std::tuple<Kind, ScalarDefaultCharVariable> t;
  };
  struct IntVar {
    ENUM_CLASS(Kind, Iostat, Nextrec, Number, Pos, Recl, Size)
    template <typename... Ts, typename = common::NoLvalue<Ts...>> IntVar(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; IntVar(IntVar &&) = default; IntVar &operator=(IntVar &&) = default; IntVar(const IntVar &) = delete; IntVar &operator=(const IntVar &) = delete; IntVar() = delete;
    std::tuple<Kind, ScalarIntVariable> t;
  };
  struct LogVar {
    ENUM_CLASS(Kind, Exist, Named, Opened, Pending)
    template <typename... Ts, typename = common::NoLvalue<Ts...>> LogVar(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; LogVar(LogVar &&) = default; LogVar &operator=(LogVar &&) = default; LogVar(const LogVar &) = delete; LogVar &operator=(const LogVar &) = delete; LogVar() = delete;
    std::tuple<Kind, Scalar<Logical<Variable>>> t;
  };
  std::variant<FileUnitNumber, FileNameExpr, CharVar, IntVar, LogVar, IdExpr,
      ErrLabel>
      u;
};




struct InquireStmt {
  template <typename A, typename = common::NoLvalue<A>> InquireStmt(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; InquireStmt(InquireStmt &&) = default; InquireStmt &operator=(InquireStmt &&) = default; InquireStmt(const InquireStmt &) = delete; InquireStmt &operator=(const InquireStmt &) = delete; InquireStmt() = delete;
  struct Iolength {
    template <typename... Ts, typename = common::NoLvalue<Ts...>> Iolength(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; Iolength(Iolength &&) = default; Iolength &operator=(Iolength &&) = default; Iolength(const Iolength &) = delete; Iolength &operator=(const Iolength &) = delete; Iolength() = delete;
    std::tuple<ScalarIntVariable, std::list<OutputItem>> t;
  };
  std::variant<std::list<InquireSpec>, Iolength> u;
};


struct FormatStmt { FormatStmt(FormatStmt &&) = default; FormatStmt &operator=(FormatStmt &&) = default; FormatStmt(const FormatStmt &) = delete; FormatStmt &operator=(const FormatStmt &) = delete; FormatStmt() = delete; FormatStmt(format::FormatSpecification &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; format::FormatSpecification v; };


struct ProgramStmt { ProgramStmt(ProgramStmt &&) = default; ProgramStmt &operator=(ProgramStmt &&) = default; ProgramStmt(const ProgramStmt &) = delete; ProgramStmt &operator=(const ProgramStmt &) = delete; ProgramStmt() = delete; ProgramStmt(Name &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; Name v; };


struct EndProgramStmt { EndProgramStmt(EndProgramStmt &&) = default; EndProgramStmt &operator=(EndProgramStmt &&) = default; EndProgramStmt(const EndProgramStmt &) = delete; EndProgramStmt &operator=(const EndProgramStmt &) = delete; EndProgramStmt() = delete; EndProgramStmt(std::optional<Name> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::optional<Name> v; };




struct MainProgram {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> MainProgram(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; MainProgram(MainProgram &&) = default; MainProgram &operator=(MainProgram &&) = default; MainProgram(const MainProgram &) = delete; MainProgram &operator=(const MainProgram &) = delete; MainProgram() = delete;
  std::tuple<std::optional<Statement<ProgramStmt>>, SpecificationPart,
      ExecutionPart, std::optional<InternalSubprogramPart>,
      Statement<EndProgramStmt>>
      t;
};


struct ModuleStmt { ModuleStmt(ModuleStmt &&) = default; ModuleStmt &operator=(ModuleStmt &&) = default; ModuleStmt(const ModuleStmt &) = delete; ModuleStmt &operator=(const ModuleStmt &) = delete; ModuleStmt() = delete; ModuleStmt(Name &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; Name v; };




struct ModuleSubprogram {
  template <typename A, typename = common::NoLvalue<A>> ModuleSubprogram(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; ModuleSubprogram(ModuleSubprogram &&) = default; ModuleSubprogram &operator=(ModuleSubprogram &&) = default; ModuleSubprogram(const ModuleSubprogram &) = delete; ModuleSubprogram &operator=(const ModuleSubprogram &) = delete; ModuleSubprogram() = delete;
  std::variant<common::Indirection<FunctionSubprogram>,
      common::Indirection<SubroutineSubprogram>,
      common::Indirection<SeparateModuleSubprogram>>
      u;
};


struct ModuleSubprogramPart {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> ModuleSubprogramPart(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; ModuleSubprogramPart(ModuleSubprogramPart &&) = default; ModuleSubprogramPart &operator=(ModuleSubprogramPart &&) = default; ModuleSubprogramPart(const ModuleSubprogramPart &) = delete; ModuleSubprogramPart &operator=(const ModuleSubprogramPart &) = delete; ModuleSubprogramPart() = delete;
  std::tuple<Statement<ContainsStmt>, std::list<ModuleSubprogram>> t;
};


struct EndModuleStmt { EndModuleStmt(EndModuleStmt &&) = default; EndModuleStmt &operator=(EndModuleStmt &&) = default; EndModuleStmt(const EndModuleStmt &) = delete; EndModuleStmt &operator=(const EndModuleStmt &) = delete; EndModuleStmt() = delete; EndModuleStmt(std::optional<Name> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::optional<Name> v; };




struct Module {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> Module(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; Module(Module &&) = default; Module &operator=(Module &&) = default; Module(const Module &) = delete; Module &operator=(const Module &) = delete; Module() = delete;
  std::tuple<Statement<ModuleStmt>, SpecificationPart,
      std::optional<ModuleSubprogramPart>, Statement<EndModuleStmt>>
      t;
};





struct Rename {
  template <typename A, typename = common::NoLvalue<A>> Rename(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; Rename(Rename &&) = default; Rename &operator=(Rename &&) = default; Rename(const Rename &) = delete; Rename &operator=(const Rename &) = delete; Rename() = delete;
  struct Names {
    template <typename... Ts, typename = common::NoLvalue<Ts...>> Names(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; Names(Names &&) = default; Names &operator=(Names &&) = default; Names(const Names &) = delete; Names &operator=(const Names &) = delete; Names() = delete;
    std::tuple<Name, Name> t;
  };
  struct Operators {
    template <typename... Ts, typename = common::NoLvalue<Ts...>> Operators(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; Operators(Operators &&) = default; Operators &operator=(Operators &&) = default; Operators(const Operators &) = delete; Operators &operator=(const Operators &) = delete; Operators() = delete;
    std::tuple<DefinedOpName, DefinedOpName> t;
  };
  std::variant<Names, Operators> u;
};


struct ParentIdentifier {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> ParentIdentifier(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; ParentIdentifier(ParentIdentifier &&) = default; ParentIdentifier &operator=(ParentIdentifier &&) = default; ParentIdentifier(const ParentIdentifier &) = delete; ParentIdentifier &operator=(const ParentIdentifier &) = delete; ParentIdentifier() = delete;
  std::tuple<Name, std::optional<Name>> t;
};


struct SubmoduleStmt {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> SubmoduleStmt(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; SubmoduleStmt(SubmoduleStmt &&) = default; SubmoduleStmt &operator=(SubmoduleStmt &&) = default; SubmoduleStmt(const SubmoduleStmt &) = delete; SubmoduleStmt &operator=(const SubmoduleStmt &) = delete; SubmoduleStmt() = delete;
  std::tuple<ParentIdentifier, Name> t;
};


struct EndSubmoduleStmt { EndSubmoduleStmt(EndSubmoduleStmt &&) = default; EndSubmoduleStmt &operator=(EndSubmoduleStmt &&) = default; EndSubmoduleStmt(const EndSubmoduleStmt &) = delete; EndSubmoduleStmt &operator=(const EndSubmoduleStmt &) = delete; EndSubmoduleStmt() = delete; EndSubmoduleStmt(std::optional<Name> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::optional<Name> v; };




struct Submodule {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> Submodule(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; Submodule(Submodule &&) = default; Submodule &operator=(Submodule &&) = default; Submodule(const Submodule &) = delete; Submodule &operator=(const Submodule &) = delete; Submodule() = delete;
  std::tuple<Statement<SubmoduleStmt>, SpecificationPart,
      std::optional<ModuleSubprogramPart>, Statement<EndSubmoduleStmt>>
      t;
};


struct BlockDataStmt { BlockDataStmt(BlockDataStmt &&) = default; BlockDataStmt &operator=(BlockDataStmt &&) = default; BlockDataStmt(const BlockDataStmt &) = delete; BlockDataStmt &operator=(const BlockDataStmt &) = delete; BlockDataStmt() = delete; BlockDataStmt(std::optional<Name> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::optional<Name> v; };


struct EndBlockDataStmt { EndBlockDataStmt(EndBlockDataStmt &&) = default; EndBlockDataStmt &operator=(EndBlockDataStmt &&) = default; EndBlockDataStmt(const EndBlockDataStmt &) = delete; EndBlockDataStmt &operator=(const EndBlockDataStmt &) = delete; EndBlockDataStmt() = delete; EndBlockDataStmt(std::optional<Name> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::optional<Name> v; };


struct BlockData {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> BlockData(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; BlockData(BlockData &&) = default; BlockData &operator=(BlockData &&) = default; BlockData(const BlockData &) = delete; BlockData &operator=(const BlockData &) = delete; BlockData() = delete;
  std::tuple<Statement<BlockDataStmt>, SpecificationPart,
      Statement<EndBlockDataStmt>>
      t;
};







struct GenericSpec {
  template <typename A, typename = common::NoLvalue<A>> GenericSpec(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; GenericSpec(GenericSpec &&) = default; GenericSpec &operator=(GenericSpec &&) = default; GenericSpec(const GenericSpec &) = delete; GenericSpec &operator=(const GenericSpec &) = delete; GenericSpec() = delete;
  struct Assignment { Assignment() {} Assignment(const Assignment &) {} Assignment(Assignment &&) {} Assignment &operator=(const Assignment &) { return *this; }; Assignment &operator=(Assignment &&) { return *this; }; using EmptyTrait = std::true_type; };
  struct ReadFormatted { ReadFormatted() {} ReadFormatted(const ReadFormatted &) {} ReadFormatted(ReadFormatted &&) {} ReadFormatted &operator=(const ReadFormatted &) { return *this; }; ReadFormatted &operator=(ReadFormatted &&) { return *this; }; using EmptyTrait = std::true_type; };
  struct ReadUnformatted { ReadUnformatted() {} ReadUnformatted(const ReadUnformatted &) {} ReadUnformatted(ReadUnformatted &&) {} ReadUnformatted &operator=(const ReadUnformatted &) { return *this; }; ReadUnformatted &operator=(ReadUnformatted &&) { return *this; }; using EmptyTrait = std::true_type; };
  struct WriteFormatted { WriteFormatted() {} WriteFormatted(const WriteFormatted &) {} WriteFormatted(WriteFormatted &&) {} WriteFormatted &operator=(const WriteFormatted &) { return *this; }; WriteFormatted &operator=(WriteFormatted &&) { return *this; }; using EmptyTrait = std::true_type; };
  struct WriteUnformatted { WriteUnformatted() {} WriteUnformatted(const WriteUnformatted &) {} WriteUnformatted(WriteUnformatted &&) {} WriteUnformatted &operator=(const WriteUnformatted &) { return *this; }; WriteUnformatted &operator=(WriteUnformatted &&) { return *this; }; using EmptyTrait = std::true_type; };
  CharBlock source;
  std::variant<Name, DefinedOperator, Assignment, ReadFormatted,
      ReadUnformatted, WriteFormatted, WriteUnformatted>
      u;
};



struct GenericStmt {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> GenericStmt(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; GenericStmt(GenericStmt &&) = default; GenericStmt &operator=(GenericStmt &&) = default; GenericStmt(const GenericStmt &) = delete; GenericStmt &operator=(const GenericStmt &) = delete; GenericStmt() = delete;
  std::tuple<std::optional<AccessSpec>, GenericSpec, std::list<Name>> t;
};


struct InterfaceStmt {
  template <typename A, typename = common::NoLvalue<A>> InterfaceStmt(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; InterfaceStmt(InterfaceStmt &&) = default; InterfaceStmt &operator=(InterfaceStmt &&) = default; InterfaceStmt(const InterfaceStmt &) = delete; InterfaceStmt &operator=(const InterfaceStmt &) = delete; InterfaceStmt() = delete;

  InterfaceStmt(Abstract x) : u{x} {}

  std::variant<std::optional<GenericSpec>, Abstract> u;
};



struct Only {
  template <typename A, typename = common::NoLvalue<A>> Only(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; Only(Only &&) = default; Only &operator=(Only &&) = default; Only(const Only &) = delete; Only &operator=(const Only &) = delete; Only() = delete;
  std::variant<common::Indirection<GenericSpec>, Name, Rename> u;
};





struct UseStmt {
  UseStmt(UseStmt &&) = default; UseStmt &operator=(UseStmt &&) = default; UseStmt(const UseStmt &) = delete; UseStmt &operator=(const UseStmt &) = delete; UseStmt() = delete;
  ENUM_CLASS(ModuleNature, Intrinsic, Non_Intrinsic)
  template <typename A>
  UseStmt(std::optional<ModuleNature> &&nat, Name &&n, std::list<A> &&x)
      : nature(std::move(nat)), moduleName(std::move(n)), u(std::move(x)) {}
  std::optional<ModuleNature> nature;
  Name moduleName;
  std::variant<std::list<Rename>, std::list<Only>> u;
};




struct ProcAttrSpec {
  template <typename A, typename = common::NoLvalue<A>> ProcAttrSpec(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; ProcAttrSpec(ProcAttrSpec &&) = default; ProcAttrSpec &operator=(ProcAttrSpec &&) = default; ProcAttrSpec(const ProcAttrSpec &) = delete; ProcAttrSpec &operator=(const ProcAttrSpec &) = delete; ProcAttrSpec() = delete;
  std::variant<AccessSpec, LanguageBindingSpec, IntentSpec, Optional, Pointer,
      Protected, Save>
      u;
};




struct ProcedureDeclarationStmt {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> ProcedureDeclarationStmt(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; ProcedureDeclarationStmt(ProcedureDeclarationStmt &&) = default; ProcedureDeclarationStmt &operator=(ProcedureDeclarationStmt &&) = default; ProcedureDeclarationStmt(const ProcedureDeclarationStmt &) = delete; ProcedureDeclarationStmt &operator=(const ProcedureDeclarationStmt &) = delete; ProcedureDeclarationStmt() = delete;
  std::tuple<std::optional<ProcInterface>, std::list<ProcAttrSpec>,
      std::list<ProcDecl>>
      t;
};




struct PrefixSpec {
  template <typename A, typename = common::NoLvalue<A>> PrefixSpec(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; PrefixSpec(PrefixSpec &&) = default; PrefixSpec &operator=(PrefixSpec &&) = default; PrefixSpec(const PrefixSpec &) = delete; PrefixSpec &operator=(const PrefixSpec &) = delete; PrefixSpec() = delete;
  struct Elemental { Elemental() {} Elemental(const Elemental &) {} Elemental(Elemental &&) {} Elemental &operator=(const Elemental &) { return *this; }; Elemental &operator=(Elemental &&) { return *this; }; using EmptyTrait = std::true_type; };
  struct Impure { Impure() {} Impure(const Impure &) {} Impure(Impure &&) {} Impure &operator=(const Impure &) { return *this; }; Impure &operator=(Impure &&) { return *this; }; using EmptyTrait = std::true_type; };
  struct Module { Module() {} Module(const Module &) {} Module(Module &&) {} Module &operator=(const Module &) { return *this; }; Module &operator=(Module &&) { return *this; }; using EmptyTrait = std::true_type; };
  struct Non_Recursive { Non_Recursive() {} Non_Recursive(const Non_Recursive &) {} Non_Recursive(Non_Recursive &&) {} Non_Recursive &operator=(const Non_Recursive &) { return *this; }; Non_Recursive &operator=(Non_Recursive &&) { return *this; }; using EmptyTrait = std::true_type; };
  struct Pure { Pure() {} Pure(const Pure &) {} Pure(Pure &&) {} Pure &operator=(const Pure &) { return *this; }; Pure &operator=(Pure &&) { return *this; }; using EmptyTrait = std::true_type; };
  struct Recursive { Recursive() {} Recursive(const Recursive &) {} Recursive(Recursive &&) {} Recursive &operator=(const Recursive &) { return *this; }; Recursive &operator=(Recursive &&) { return *this; }; using EmptyTrait = std::true_type; };
  std::variant<DeclarationTypeSpec, Elemental, Impure, Module, Non_Recursive,
      Pure, Recursive>
      u;
};




struct Suffix {
  Suffix(Suffix &&) = default; Suffix &operator=(Suffix &&) = default; Suffix(const Suffix &) = delete; Suffix &operator=(const Suffix &) = delete; Suffix() = delete;
  Suffix(LanguageBindingSpec &&lbs, std::optional<Name> &&rn)
      : binding(std::move(lbs)), resultName(std::move(rn)) {}
  Suffix(Name &&rn, std::optional<LanguageBindingSpec> &&lbs)
      : binding(std::move(lbs)), resultName(std::move(rn)) {}
  std::optional<LanguageBindingSpec> binding;
  std::optional<Name> resultName;
};





struct FunctionStmt {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> FunctionStmt(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; FunctionStmt(FunctionStmt &&) = default; FunctionStmt &operator=(FunctionStmt &&) = default; FunctionStmt(const FunctionStmt &) = delete; FunctionStmt &operator=(const FunctionStmt &) = delete; FunctionStmt() = delete;
  std::tuple<std::list<PrefixSpec>, Name, std::list<Name>,
      std::optional<Suffix>>
      t;
};


struct EndFunctionStmt { EndFunctionStmt(EndFunctionStmt &&) = default; EndFunctionStmt &operator=(EndFunctionStmt &&) = default; EndFunctionStmt(const EndFunctionStmt &) = delete; EndFunctionStmt &operator=(const EndFunctionStmt &) = delete; EndFunctionStmt() = delete; EndFunctionStmt(std::optional<Name> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::optional<Name> v; };


struct DummyArg {
  template <typename A, typename = common::NoLvalue<A>> DummyArg(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; DummyArg(DummyArg &&) = default; DummyArg &operator=(DummyArg &&) = default; DummyArg(const DummyArg &) = delete; DummyArg &operator=(const DummyArg &) = delete; DummyArg() = delete;
  std::variant<Name, Star> u;
};




struct SubroutineStmt {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> SubroutineStmt(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; SubroutineStmt(SubroutineStmt &&) = default; SubroutineStmt &operator=(SubroutineStmt &&) = default; SubroutineStmt(const SubroutineStmt &) = delete; SubroutineStmt &operator=(const SubroutineStmt &) = delete; SubroutineStmt() = delete;
  std::tuple<std::list<PrefixSpec>, Name, std::list<DummyArg>,
      std::optional<LanguageBindingSpec>>
      t;
};


struct EndSubroutineStmt { EndSubroutineStmt(EndSubroutineStmt &&) = default; EndSubroutineStmt &operator=(EndSubroutineStmt &&) = default; EndSubroutineStmt(const EndSubroutineStmt &) = delete; EndSubroutineStmt &operator=(const EndSubroutineStmt &) = delete; EndSubroutineStmt() = delete; EndSubroutineStmt(std::optional<Name> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::optional<Name> v; };




struct InterfaceBody {
  template <typename A, typename = common::NoLvalue<A>> InterfaceBody(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; InterfaceBody(InterfaceBody &&) = default; InterfaceBody &operator=(InterfaceBody &&) = default; InterfaceBody(const InterfaceBody &) = delete; InterfaceBody &operator=(const InterfaceBody &) = delete; InterfaceBody() = delete;
  struct Function {
    template <typename... Ts, typename = common::NoLvalue<Ts...>> Function(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; Function(Function &&) = default; Function &operator=(Function &&) = default; Function(const Function &) = delete; Function &operator=(const Function &) = delete; Function() = delete;
    std::tuple<Statement<FunctionStmt>, common::Indirection<SpecificationPart>,
        Statement<EndFunctionStmt>>
        t;
  };
  struct Subroutine {
    template <typename... Ts, typename = common::NoLvalue<Ts...>> Subroutine(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; Subroutine(Subroutine &&) = default; Subroutine &operator=(Subroutine &&) = default; Subroutine(const Subroutine &) = delete; Subroutine &operator=(const Subroutine &) = delete; Subroutine() = delete;
    std::tuple<Statement<SubroutineStmt>,
        common::Indirection<SpecificationPart>, Statement<EndSubroutineStmt>>
        t;
  };
  std::variant<Function, Subroutine> u;
};


struct ProcedureStmt {
  ENUM_CLASS(Kind, ModuleProcedure, Procedure)
  template <typename... Ts, typename = common::NoLvalue<Ts...>> ProcedureStmt(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; ProcedureStmt(ProcedureStmt &&) = default; ProcedureStmt &operator=(ProcedureStmt &&) = default; ProcedureStmt(const ProcedureStmt &) = delete; ProcedureStmt &operator=(const ProcedureStmt &) = delete; ProcedureStmt() = delete;
  std::tuple<Kind, std::list<Name>> t;
};


struct InterfaceSpecification {
  template <typename A, typename = common::NoLvalue<A>> InterfaceSpecification(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; InterfaceSpecification(InterfaceSpecification &&) = default; InterfaceSpecification &operator=(InterfaceSpecification &&) = default; InterfaceSpecification(const InterfaceSpecification &) = delete; InterfaceSpecification &operator=(const InterfaceSpecification &) = delete; InterfaceSpecification() = delete;
  std::variant<InterfaceBody, Statement<ProcedureStmt>> u;
};


struct EndInterfaceStmt { EndInterfaceStmt(EndInterfaceStmt &&) = default; EndInterfaceStmt &operator=(EndInterfaceStmt &&) = default; EndInterfaceStmt(const EndInterfaceStmt &) = delete; EndInterfaceStmt &operator=(const EndInterfaceStmt &) = delete; EndInterfaceStmt() = delete; EndInterfaceStmt(std::optional<GenericSpec> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::optional<GenericSpec> v; };



struct InterfaceBlock {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> InterfaceBlock(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; InterfaceBlock(InterfaceBlock &&) = default; InterfaceBlock &operator=(InterfaceBlock &&) = default; InterfaceBlock(const InterfaceBlock &) = delete; InterfaceBlock &operator=(const InterfaceBlock &) = delete; InterfaceBlock() = delete;
  std::tuple<Statement<InterfaceStmt>, std::list<InterfaceSpecification>,
      Statement<EndInterfaceStmt>>
      t;
};


struct ExternalStmt { ExternalStmt(ExternalStmt &&) = default; ExternalStmt &operator=(ExternalStmt &&) = default; ExternalStmt(const ExternalStmt &) = delete; ExternalStmt &operator=(const ExternalStmt &) = delete; ExternalStmt() = delete; ExternalStmt(std::list<Name> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::list<Name> v; };


struct IntrinsicStmt { IntrinsicStmt(IntrinsicStmt &&) = default; IntrinsicStmt &operator=(IntrinsicStmt &&) = default; IntrinsicStmt(const IntrinsicStmt &) = delete; IntrinsicStmt &operator=(const IntrinsicStmt &) = delete; IntrinsicStmt() = delete; IntrinsicStmt(std::list<Name> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::list<Name> v; };



struct ProcedureDesignator {
  template <typename A, typename = common::NoLvalue<A>> ProcedureDesignator(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; ProcedureDesignator(ProcedureDesignator &&) = default; ProcedureDesignator &operator=(ProcedureDesignator &&) = default; ProcedureDesignator(const ProcedureDesignator &) = delete; ProcedureDesignator &operator=(const ProcedureDesignator &) = delete; ProcedureDesignator() = delete;
  std::variant<Name, ProcComponentRef> u;
};


struct AltReturnSpec { AltReturnSpec(AltReturnSpec &&) = default; AltReturnSpec &operator=(AltReturnSpec &&) = default; AltReturnSpec(const AltReturnSpec &) = delete; AltReturnSpec &operator=(const AltReturnSpec &) = delete; AltReturnSpec() = delete; AltReturnSpec(Label &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; Label v; };




struct ActualArg {
  struct PercentRef { PercentRef(PercentRef &&) = default; PercentRef &operator=(PercentRef &&) = default; PercentRef(const PercentRef &) = delete; PercentRef &operator=(const PercentRef &) = delete; PercentRef() = delete; PercentRef(Variable &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; Variable v; };
  struct PercentVal { PercentVal(PercentVal &&) = default; PercentVal &operator=(PercentVal &&) = default; PercentVal(const PercentVal &) = delete; PercentVal &operator=(const PercentVal &) = delete; PercentVal() = delete; PercentVal(Expr &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; Expr v; };
  template <typename A, typename = common::NoLvalue<A>> ActualArg(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; ActualArg(ActualArg &&) = default; ActualArg &operator=(ActualArg &&) = default; ActualArg(const ActualArg &) = delete; ActualArg &operator=(const ActualArg &) = delete; ActualArg() = delete;
  ActualArg(Expr &&x) : u{common::Indirection<Expr>(std::move(x))} {}
  std::variant<common::Indirection<Expr>, AltReturnSpec, PercentRef, PercentVal>
      u;
};


struct ActualArgSpec {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> ActualArgSpec(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; ActualArgSpec(ActualArgSpec &&) = default; ActualArgSpec &operator=(ActualArgSpec &&) = default; ActualArgSpec(const ActualArgSpec &) = delete; ActualArgSpec &operator=(const ActualArgSpec &) = delete; ActualArgSpec() = delete;
  std::tuple<std::optional<Keyword>, ActualArg> t;
};


struct Call {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> Call(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; Call(Call &&) = default; Call &operator=(Call &&) = default; Call(const Call &) = delete; Call &operator=(const Call &) = delete; Call() = delete;
  CharBlock source;
  std::tuple<ProcedureDesignator, std::list<ActualArgSpec>> t;
};

struct FunctionReference {
  FunctionReference(FunctionReference &&) = default; FunctionReference &operator=(FunctionReference &&) = default; FunctionReference(const FunctionReference &) = delete; FunctionReference &operator=(const FunctionReference &) = delete; FunctionReference() = delete; FunctionReference(Call &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; Call v;
  Designator ConvertToArrayElementRef();
  StructureConstructor ConvertToStructureConstructor(
      const semantics::DerivedTypeSpec &);
};


struct CallStmt {
  CallStmt(CallStmt &&) = default; CallStmt &operator=(CallStmt &&) = default; CallStmt(const CallStmt &) = delete; CallStmt &operator=(const CallStmt &) = delete; CallStmt() = delete; CallStmt(Call &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; Call v;
  mutable common::ForwardOwningPointer<evaluate::ProcedureRef>
      typedCall;
};




struct FunctionSubprogram {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> FunctionSubprogram(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; FunctionSubprogram(FunctionSubprogram &&) = default; FunctionSubprogram &operator=(FunctionSubprogram &&) = default; FunctionSubprogram(const FunctionSubprogram &) = delete; FunctionSubprogram &operator=(const FunctionSubprogram &) = delete; FunctionSubprogram() = delete;
  std::tuple<Statement<FunctionStmt>, SpecificationPart, ExecutionPart,
      std::optional<InternalSubprogramPart>, Statement<EndFunctionStmt>>
      t;
};




struct SubroutineSubprogram {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> SubroutineSubprogram(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; SubroutineSubprogram(SubroutineSubprogram &&) = default; SubroutineSubprogram &operator=(SubroutineSubprogram &&) = default; SubroutineSubprogram(const SubroutineSubprogram &) = delete; SubroutineSubprogram &operator=(const SubroutineSubprogram &) = delete; SubroutineSubprogram() = delete;
  std::tuple<Statement<SubroutineStmt>, SpecificationPart, ExecutionPart,
      std::optional<InternalSubprogramPart>, Statement<EndSubroutineStmt>>
      t;
};


struct MpSubprogramStmt { MpSubprogramStmt(MpSubprogramStmt &&) = default; MpSubprogramStmt &operator=(MpSubprogramStmt &&) = default; MpSubprogramStmt(const MpSubprogramStmt &) = delete; MpSubprogramStmt &operator=(const MpSubprogramStmt &) = delete; MpSubprogramStmt() = delete; MpSubprogramStmt(Name &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; Name v; };


struct EndMpSubprogramStmt { EndMpSubprogramStmt(EndMpSubprogramStmt &&) = default; EndMpSubprogramStmt &operator=(EndMpSubprogramStmt &&) = default; EndMpSubprogramStmt(const EndMpSubprogramStmt &) = delete; EndMpSubprogramStmt &operator=(const EndMpSubprogramStmt &) = delete; EndMpSubprogramStmt() = delete; EndMpSubprogramStmt(std::optional<Name> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::optional<Name> v; };




struct SeparateModuleSubprogram {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> SeparateModuleSubprogram(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; SeparateModuleSubprogram(SeparateModuleSubprogram &&) = default; SeparateModuleSubprogram &operator=(SeparateModuleSubprogram &&) = default; SeparateModuleSubprogram(const SeparateModuleSubprogram &) = delete; SeparateModuleSubprogram &operator=(const SeparateModuleSubprogram &) = delete; SeparateModuleSubprogram() = delete;
  std::tuple<Statement<MpSubprogramStmt>, SpecificationPart, ExecutionPart,
      std::optional<InternalSubprogramPart>, Statement<EndMpSubprogramStmt>>
      t;
};


struct EntryStmt {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> EntryStmt(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; EntryStmt(EntryStmt &&) = default; EntryStmt &operator=(EntryStmt &&) = default; EntryStmt(const EntryStmt &) = delete; EntryStmt &operator=(const EntryStmt &) = delete; EntryStmt() = delete;
  std::tuple<Name, std::list<DummyArg>, std::optional<Suffix>> t;
};


struct ReturnStmt { ReturnStmt(ReturnStmt &&) = default; ReturnStmt &operator=(ReturnStmt &&) = default; ReturnStmt(const ReturnStmt &) = delete; ReturnStmt &operator=(const ReturnStmt &) = delete; ReturnStmt() = delete; ReturnStmt(std::optional<ScalarIntExpr> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::optional<ScalarIntExpr> v; };



struct StmtFunctionStmt {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> StmtFunctionStmt(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; StmtFunctionStmt(StmtFunctionStmt &&) = default; StmtFunctionStmt &operator=(StmtFunctionStmt &&) = default; StmtFunctionStmt(const StmtFunctionStmt &) = delete; StmtFunctionStmt &operator=(const StmtFunctionStmt &) = delete; StmtFunctionStmt() = delete;
  std::tuple<Name, std::list<Name>, Scalar<Expr>> t;
  Statement<ActionStmt> ConvertToAssignment();
};




struct CompilerDirective {
  template <typename A, typename = common::NoLvalue<A>> CompilerDirective(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; CompilerDirective(CompilerDirective &&) = default; CompilerDirective &operator=(CompilerDirective &&) = default; CompilerDirective(const CompilerDirective &) = delete; CompilerDirective &operator=(const CompilerDirective &) = delete; CompilerDirective() = delete;
  struct IgnoreTKR {
    template <typename... Ts, typename = common::NoLvalue<Ts...>> IgnoreTKR(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; IgnoreTKR(IgnoreTKR &&) = default; IgnoreTKR &operator=(IgnoreTKR &&) = default; IgnoreTKR(const IgnoreTKR &) = delete; IgnoreTKR &operator=(const IgnoreTKR &) = delete; IgnoreTKR() = delete;
    std::tuple<std::list<const char *>, Name> t;
  };
  struct NameValue {
    template <typename... Ts, typename = common::NoLvalue<Ts...>> NameValue(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; NameValue(NameValue &&) = default; NameValue &operator=(NameValue &&) = default; NameValue(const NameValue &) = delete; NameValue &operator=(const NameValue &) = delete; NameValue() = delete;
    std::tuple<Name, std::optional<std::uint64_t>> t;
  };
  CharBlock source;
  std::variant<std::list<IgnoreTKR>, std::list<NameValue>> u;
};


struct BasedPointer {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> BasedPointer(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; BasedPointer(BasedPointer &&) = default; BasedPointer &operator=(BasedPointer &&) = default; BasedPointer(const BasedPointer &) = delete; BasedPointer &operator=(const BasedPointer &) = delete; BasedPointer() = delete;
  std::tuple<ObjectName, ObjectName, std::optional<ArraySpec>> t;
};
struct BasedPointerStmt { BasedPointerStmt(BasedPointerStmt &&) = default; BasedPointerStmt &operator=(BasedPointerStmt &&) = default; BasedPointerStmt(const BasedPointerStmt &) = delete; BasedPointerStmt &operator=(const BasedPointerStmt &) = delete; BasedPointerStmt() = delete; BasedPointerStmt(std::list<BasedPointer> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::list<BasedPointer> v; };

struct Union;
struct StructureDef;

struct StructureField {
  template <typename A, typename = common::NoLvalue<A>> StructureField(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; StructureField(StructureField &&) = default; StructureField &operator=(StructureField &&) = default; StructureField(const StructureField &) = delete; StructureField &operator=(const StructureField &) = delete; StructureField() = delete;
  std::variant<Statement<DataComponentDefStmt>,
      common::Indirection<StructureDef>, common::Indirection<Union>>
      u;
};

struct Map {
  struct MapStmt { MapStmt() {} MapStmt(const MapStmt &) {} MapStmt(MapStmt &&) {} MapStmt &operator=(const MapStmt &) { return *this; }; MapStmt &operator=(MapStmt &&) { return *this; }; using EmptyTrait = std::true_type; };
  struct EndMapStmt { EndMapStmt() {} EndMapStmt(const EndMapStmt &) {} EndMapStmt(EndMapStmt &&) {} EndMapStmt &operator=(const EndMapStmt &) { return *this; }; EndMapStmt &operator=(EndMapStmt &&) { return *this; }; using EmptyTrait = std::true_type; };
  template <typename... Ts, typename = common::NoLvalue<Ts...>> Map(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; Map(Map &&) = default; Map &operator=(Map &&) = default; Map(const Map &) = delete; Map &operator=(const Map &) = delete; Map() = delete;
  std::tuple<Statement<MapStmt>, std::list<StructureField>,
      Statement<EndMapStmt>>
      t;
};

struct Union {
  struct UnionStmt { UnionStmt() {} UnionStmt(const UnionStmt &) {} UnionStmt(UnionStmt &&) {} UnionStmt &operator=(const UnionStmt &) { return *this; }; UnionStmt &operator=(UnionStmt &&) { return *this; }; using EmptyTrait = std::true_type; };
  struct EndUnionStmt { EndUnionStmt() {} EndUnionStmt(const EndUnionStmt &) {} EndUnionStmt(EndUnionStmt &&) {} EndUnionStmt &operator=(const EndUnionStmt &) { return *this; }; EndUnionStmt &operator=(EndUnionStmt &&) { return *this; }; using EmptyTrait = std::true_type; };
  template <typename... Ts, typename = common::NoLvalue<Ts...>> Union(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; Union(Union &&) = default; Union &operator=(Union &&) = default; Union(const Union &) = delete; Union &operator=(const Union &) = delete; Union() = delete;
  std::tuple<Statement<UnionStmt>, std::list<Map>, Statement<EndUnionStmt>> t;
};

struct StructureStmt {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> StructureStmt(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; StructureStmt(StructureStmt &&) = default; StructureStmt &operator=(StructureStmt &&) = default; StructureStmt(const StructureStmt &) = delete; StructureStmt &operator=(const StructureStmt &) = delete; StructureStmt() = delete;
  std::tuple<Name, bool , std::list<EntityDecl>> t;
};

struct StructureDef {
  struct EndStructureStmt { EndStructureStmt() {} EndStructureStmt(const EndStructureStmt &) {} EndStructureStmt(EndStructureStmt &&) {} EndStructureStmt &operator=(const EndStructureStmt &) { return *this; }; EndStructureStmt &operator=(EndStructureStmt &&) { return *this; }; using EmptyTrait = std::true_type; };
  template <typename... Ts, typename = common::NoLvalue<Ts...>> StructureDef(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; StructureDef(StructureDef &&) = default; StructureDef &operator=(StructureDef &&) = default; StructureDef(const StructureDef &) = delete; StructureDef &operator=(const StructureDef &) = delete; StructureDef() = delete;
  std::tuple<Statement<StructureStmt>, std::list<StructureField>,
      Statement<EndStructureStmt>>
      t;
};



struct OldParameterStmt { OldParameterStmt(OldParameterStmt &&) = default; OldParameterStmt &operator=(OldParameterStmt &&) = default; OldParameterStmt(const OldParameterStmt &) = delete; OldParameterStmt &operator=(const OldParameterStmt &) = delete; OldParameterStmt() = delete; OldParameterStmt(std::list<NamedConstantDef> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::list<NamedConstantDef> v; };


struct ArithmeticIfStmt {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> ArithmeticIfStmt(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; ArithmeticIfStmt(ArithmeticIfStmt &&) = default; ArithmeticIfStmt &operator=(ArithmeticIfStmt &&) = default; ArithmeticIfStmt(const ArithmeticIfStmt &) = delete; ArithmeticIfStmt &operator=(const ArithmeticIfStmt &) = delete; ArithmeticIfStmt() = delete;
  std::tuple<Expr, Label, Label, Label> t;
};

struct AssignStmt {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> AssignStmt(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; AssignStmt(AssignStmt &&) = default; AssignStmt &operator=(AssignStmt &&) = default; AssignStmt(const AssignStmt &) = delete; AssignStmt &operator=(const AssignStmt &) = delete; AssignStmt() = delete;
  std::tuple<Label, Name> t;
};

struct AssignedGotoStmt {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> AssignedGotoStmt(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; AssignedGotoStmt(AssignedGotoStmt &&) = default; AssignedGotoStmt &operator=(AssignedGotoStmt &&) = default; AssignedGotoStmt(const AssignedGotoStmt &) = delete; AssignedGotoStmt &operator=(const AssignedGotoStmt &) = delete; AssignedGotoStmt() = delete;
  std::tuple<Name, std::list<Label>> t;
};

struct PauseStmt { PauseStmt(PauseStmt &&) = default; PauseStmt &operator=(PauseStmt &&) = default; PauseStmt(const PauseStmt &) = delete; PauseStmt &operator=(const PauseStmt &) = delete; PauseStmt() = delete; PauseStmt(std::optional<StopCode> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::optional<StopCode> v; };




struct OmpProcBindClause {
  ENUM_CLASS(Type, Close, Master, Spread)
  OmpProcBindClause(OmpProcBindClause &&) = default; OmpProcBindClause &operator=(OmpProcBindClause &&) = default; OmpProcBindClause(const OmpProcBindClause &) = delete; OmpProcBindClause &operator=(const OmpProcBindClause &) = delete; OmpProcBindClause() = delete; OmpProcBindClause(Type &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; Type v;
};


struct OmpDefaultClause {
  ENUM_CLASS(Type, Private, Firstprivate, Shared, None)
  OmpDefaultClause(OmpDefaultClause &&) = default; OmpDefaultClause &operator=(OmpDefaultClause &&) = default; OmpDefaultClause(const OmpDefaultClause &) = delete; OmpDefaultClause &operator=(const OmpDefaultClause &) = delete; OmpDefaultClause() = delete; OmpDefaultClause(Type &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; Type v;
};





struct OmpObject {
  template <typename A, typename = common::NoLvalue<A>> OmpObject(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; OmpObject(OmpObject &&) = default; OmpObject &operator=(OmpObject &&) = default; OmpObject(const OmpObject &) = delete; OmpObject &operator=(const OmpObject &) = delete; OmpObject() = delete;
  std::variant<Designator, Name> u;
};

struct OmpObjectList { OmpObjectList(OmpObjectList &&) = default; OmpObjectList &operator=(OmpObjectList &&) = default; OmpObjectList(const OmpObjectList &) = delete; OmpObjectList &operator=(const OmpObjectList &) = delete; OmpObjectList() = delete; OmpObjectList(std::list<OmpObject> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::list<OmpObject> v; };


struct OmpMapType {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> OmpMapType(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; OmpMapType(OmpMapType &&) = default; OmpMapType &operator=(OmpMapType &&) = default; OmpMapType(const OmpMapType &) = delete; OmpMapType &operator=(const OmpMapType &) = delete; OmpMapType() = delete;
  struct Always { Always() {} Always(const Always &) {} Always(Always &&) {} Always &operator=(const Always &) { return *this; }; Always &operator=(Always &&) { return *this; }; using EmptyTrait = std::true_type; };
  ENUM_CLASS(Type, To, From, Tofrom, Alloc, Release, Delete)
  std::tuple<std::optional<Always>, Type> t;
};


struct OmpMapClause {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> OmpMapClause(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; OmpMapClause(OmpMapClause &&) = default; OmpMapClause &operator=(OmpMapClause &&) = default; OmpMapClause(const OmpMapClause &) = delete; OmpMapClause &operator=(const OmpMapClause &) = delete; OmpMapClause() = delete;
  std::tuple<std::optional<OmpMapType>, OmpObjectList> t;
};


struct OmpDefaultmapClause {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> OmpDefaultmapClause(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; OmpDefaultmapClause(OmpDefaultmapClause &&) = default; OmpDefaultmapClause &operator=(OmpDefaultmapClause &&) = default; OmpDefaultmapClause(const OmpDefaultmapClause &) = delete; OmpDefaultmapClause &operator=(const OmpDefaultmapClause &) = delete; OmpDefaultmapClause() = delete;
  ENUM_CLASS(ImplicitBehavior, Tofrom)
  ENUM_CLASS(VariableCategory, Scalar)
  std::tuple<ImplicitBehavior, std::optional<VariableCategory>> t;
};


struct OmpScheduleModifierType {
  ENUM_CLASS(ModType, Monotonic, Nonmonotonic, Simd)
  OmpScheduleModifierType(OmpScheduleModifierType &&) = default; OmpScheduleModifierType &operator=(OmpScheduleModifierType &&) = default; OmpScheduleModifierType(const OmpScheduleModifierType &) = delete; OmpScheduleModifierType &operator=(const OmpScheduleModifierType &) = delete; OmpScheduleModifierType() = delete; OmpScheduleModifierType(ModType &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; ModType v;
};

struct OmpScheduleModifier {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> OmpScheduleModifier(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; OmpScheduleModifier(OmpScheduleModifier &&) = default; OmpScheduleModifier &operator=(OmpScheduleModifier &&) = default; OmpScheduleModifier(const OmpScheduleModifier &) = delete; OmpScheduleModifier &operator=(const OmpScheduleModifier &) = delete; OmpScheduleModifier() = delete;
  struct Modifier1 { Modifier1(Modifier1 &&) = default; Modifier1 &operator=(Modifier1 &&) = default; Modifier1(const Modifier1 &) = delete; Modifier1 &operator=(const Modifier1 &) = delete; Modifier1() = delete; Modifier1(OmpScheduleModifierType &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; OmpScheduleModifierType v; };
  struct Modifier2 { Modifier2(Modifier2 &&) = default; Modifier2 &operator=(Modifier2 &&) = default; Modifier2(const Modifier2 &) = delete; Modifier2 &operator=(const Modifier2 &) = delete; Modifier2() = delete; Modifier2(OmpScheduleModifierType &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; OmpScheduleModifierType v; };
  std::tuple<Modifier1, std::optional<Modifier2>> t;
};



struct OmpScheduleClause {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> OmpScheduleClause(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; OmpScheduleClause(OmpScheduleClause &&) = default; OmpScheduleClause &operator=(OmpScheduleClause &&) = default; OmpScheduleClause(const OmpScheduleClause &) = delete; OmpScheduleClause &operator=(const OmpScheduleClause &) = delete; OmpScheduleClause() = delete;
  ENUM_CLASS(ScheduleType, Static, Dynamic, Guided, Auto, Runtime)
  std::tuple<std::optional<OmpScheduleModifier>, ScheduleType,
      std::optional<ScalarIntExpr>>
      t;
};


struct OmpIfClause {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> OmpIfClause(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; OmpIfClause(OmpIfClause &&) = default; OmpIfClause &operator=(OmpIfClause &&) = default; OmpIfClause(const OmpIfClause &) = delete; OmpIfClause &operator=(const OmpIfClause &) = delete; OmpIfClause() = delete;
  ENUM_CLASS(DirectiveNameModifier, Parallel, Target, TargetEnterData,
      TargetExitData, TargetData, TargetUpdate, Taskloop, Task)
  std::tuple<std::optional<DirectiveNameModifier>, ScalarLogicalExpr> t;
};


struct OmpAlignedClause {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> OmpAlignedClause(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; OmpAlignedClause(OmpAlignedClause &&) = default; OmpAlignedClause &operator=(OmpAlignedClause &&) = default; OmpAlignedClause(const OmpAlignedClause &) = delete; OmpAlignedClause &operator=(const OmpAlignedClause &) = delete; OmpAlignedClause() = delete;
  std::tuple<std::list<Name>, std::optional<ScalarIntConstantExpr>> t;
};


struct OmpLinearModifier {
  ENUM_CLASS(Type, Ref, Val, Uval)
  OmpLinearModifier(OmpLinearModifier &&) = default; OmpLinearModifier &operator=(OmpLinearModifier &&) = default; OmpLinearModifier(const OmpLinearModifier &) = delete; OmpLinearModifier &operator=(const OmpLinearModifier &) = delete; OmpLinearModifier() = delete; OmpLinearModifier(Type &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; Type v;
};



struct OmpLinearClause {
  template <typename A, typename = common::NoLvalue<A>> OmpLinearClause(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; OmpLinearClause(OmpLinearClause &&) = default; OmpLinearClause &operator=(OmpLinearClause &&) = default; OmpLinearClause(const OmpLinearClause &) = delete; OmpLinearClause &operator=(const OmpLinearClause &) = delete; OmpLinearClause() = delete;
  struct WithModifier {
    WithModifier(WithModifier &&) = default; WithModifier &operator=(WithModifier &&) = default; WithModifier(const WithModifier &) = delete; WithModifier &operator=(const WithModifier &) = delete; WithModifier() = delete;
    WithModifier(OmpLinearModifier &&m, std::list<Name> &&n,
        std::optional<ScalarIntConstantExpr> &&s)
        : modifier(std::move(m)), names(std::move(n)), step(std::move(s)) {}
    OmpLinearModifier modifier;
    std::list<Name> names;
    std::optional<ScalarIntConstantExpr> step;
  };
  struct WithoutModifier {
    WithoutModifier(WithoutModifier &&) = default; WithoutModifier &operator=(WithoutModifier &&) = default; WithoutModifier(const WithoutModifier &) = delete; WithoutModifier &operator=(const WithoutModifier &) = delete; WithoutModifier() = delete;
    WithoutModifier(
        std::list<Name> &&n, std::optional<ScalarIntConstantExpr> &&s)
        : names(std::move(n)), step(std::move(s)) {}
    std::list<Name> names;
    std::optional<ScalarIntConstantExpr> step;
  };
  std::variant<WithModifier, WithoutModifier> u;
};



struct OmpReductionOperator {
  template <typename A, typename = common::NoLvalue<A>> OmpReductionOperator(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; OmpReductionOperator(OmpReductionOperator &&) = default; OmpReductionOperator &operator=(OmpReductionOperator &&) = default; OmpReductionOperator(const OmpReductionOperator &) = delete; OmpReductionOperator &operator=(const OmpReductionOperator &) = delete; OmpReductionOperator() = delete;
  std::variant<DefinedOperator, ProcedureDesignator> u;
};



struct OmpReductionClause {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> OmpReductionClause(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; OmpReductionClause(OmpReductionClause &&) = default; OmpReductionClause &operator=(OmpReductionClause &&) = default; OmpReductionClause(const OmpReductionClause &) = delete; OmpReductionClause &operator=(const OmpReductionClause &) = delete; OmpReductionClause() = delete;
  std::tuple<OmpReductionOperator, std::list<Designator>> t;
};


struct OmpAllocateClause {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> OmpAllocateClause(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; OmpAllocateClause(OmpAllocateClause &&) = default; OmpAllocateClause &operator=(OmpAllocateClause &&) = default; OmpAllocateClause(const OmpAllocateClause &) = delete; OmpAllocateClause &operator=(const OmpAllocateClause &) = delete; OmpAllocateClause() = delete;
  struct Allocator { Allocator(Allocator &&) = default; Allocator &operator=(Allocator &&) = default; Allocator(const Allocator &) = delete; Allocator &operator=(const Allocator &) = delete; Allocator() = delete; Allocator(ScalarIntExpr &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; ScalarIntExpr v; };
  std::tuple<std::optional<Allocator>, OmpObjectList> t;
};


struct OmpDependSinkVecLength {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> OmpDependSinkVecLength(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; OmpDependSinkVecLength(OmpDependSinkVecLength &&) = default; OmpDependSinkVecLength &operator=(OmpDependSinkVecLength &&) = default; OmpDependSinkVecLength(const OmpDependSinkVecLength &) = delete; OmpDependSinkVecLength &operator=(const OmpDependSinkVecLength &) = delete; OmpDependSinkVecLength() = delete;
  std::tuple<DefinedOperator, ScalarIntConstantExpr> t;
};


struct OmpDependSinkVec {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> OmpDependSinkVec(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; OmpDependSinkVec(OmpDependSinkVec &&) = default; OmpDependSinkVec &operator=(OmpDependSinkVec &&) = default; OmpDependSinkVec(const OmpDependSinkVec &) = delete; OmpDependSinkVec &operator=(const OmpDependSinkVec &) = delete; OmpDependSinkVec() = delete;
  std::tuple<Name, std::optional<OmpDependSinkVecLength>> t;
};


struct OmpDependenceType {
  ENUM_CLASS(Type, In, Out, Inout, Source, Sink)
  OmpDependenceType(OmpDependenceType &&) = default; OmpDependenceType &operator=(OmpDependenceType &&) = default; OmpDependenceType(const OmpDependenceType &) = delete; OmpDependenceType &operator=(const OmpDependenceType &) = delete; OmpDependenceType() = delete; OmpDependenceType(Type &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; Type v;
};



struct OmpDependClause {
  template <typename A, typename = common::NoLvalue<A>> OmpDependClause(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; OmpDependClause(OmpDependClause &&) = default; OmpDependClause &operator=(OmpDependClause &&) = default; OmpDependClause(const OmpDependClause &) = delete; OmpDependClause &operator=(const OmpDependClause &) = delete; OmpDependClause() = delete;
  struct Source { Source() {} Source(const Source &) {} Source(Source &&) {} Source &operator=(const Source &) { return *this; }; Source &operator=(Source &&) { return *this; }; using EmptyTrait = std::true_type; };
  struct Sink { Sink(Sink &&) = default; Sink &operator=(Sink &&) = default; Sink(const Sink &) = delete; Sink &operator=(const Sink &) = delete; Sink() = delete; Sink(std::list<OmpDependSinkVec> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::list<OmpDependSinkVec> v; };
  struct InOut {
    template <typename... Ts, typename = common::NoLvalue<Ts...>> InOut(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; InOut(InOut &&) = default; InOut &operator=(InOut &&) = default; InOut(const InOut &) = delete; InOut &operator=(const InOut &) = delete; InOut() = delete;
    std::tuple<OmpDependenceType, std::list<Designator>> t;
  };
  std::variant<Source, Sink, InOut> u;
};


struct OmpNowait { OmpNowait() {} OmpNowait(const OmpNowait &) {} OmpNowait(OmpNowait &&) {} OmpNowait &operator=(const OmpNowait &) { return *this; }; OmpNowait &operator=(OmpNowait &&) { return *this; }; using EmptyTrait = std::true_type; };


struct OmpClause {
  template <typename A, typename = common::NoLvalue<A>> OmpClause(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; OmpClause(OmpClause &&) = default; OmpClause &operator=(OmpClause &&) = default; OmpClause(const OmpClause &) = delete; OmpClause &operator=(const OmpClause &) = delete; OmpClause() = delete;



  CharBlock source;

  std::variant<

      >
      u;
};

struct OmpClauseList {
  OmpClauseList(OmpClauseList &&) = default; OmpClauseList &operator=(OmpClauseList &&) = default; OmpClauseList(const OmpClauseList &) = delete; OmpClauseList &operator=(const OmpClauseList &) = delete; OmpClauseList() = delete; OmpClauseList(std::list<OmpClause> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::list<OmpClause> v;
  CharBlock source;
};



struct OmpSectionsDirective {
  OmpSectionsDirective(OmpSectionsDirective &&) = default; OmpSectionsDirective &operator=(OmpSectionsDirective &&) = default; OmpSectionsDirective(const OmpSectionsDirective &) = delete; OmpSectionsDirective &operator=(const OmpSectionsDirective &) = delete; OmpSectionsDirective() = delete; OmpSectionsDirective(llvm::omp::Directive &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; llvm::omp::Directive v;
  CharBlock source;
};

struct OmpBeginSectionsDirective {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> OmpBeginSectionsDirective(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; OmpBeginSectionsDirective(OmpBeginSectionsDirective &&) = default; OmpBeginSectionsDirective &operator=(OmpBeginSectionsDirective &&) = default; OmpBeginSectionsDirective(const OmpBeginSectionsDirective &) = delete; OmpBeginSectionsDirective &operator=(const OmpBeginSectionsDirective &) = delete; OmpBeginSectionsDirective() = delete;
  std::tuple<OmpSectionsDirective, OmpClauseList> t;
  CharBlock source;
};
struct OmpEndSectionsDirective {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> OmpEndSectionsDirective(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; OmpEndSectionsDirective(OmpEndSectionsDirective &&) = default; OmpEndSectionsDirective &operator=(OmpEndSectionsDirective &&) = default; OmpEndSectionsDirective(const OmpEndSectionsDirective &) = delete; OmpEndSectionsDirective &operator=(const OmpEndSectionsDirective &) = delete; OmpEndSectionsDirective() = delete;
  std::tuple<OmpSectionsDirective, OmpClauseList> t;
  CharBlock source;
};






struct OmpSectionBlocks { OmpSectionBlocks(OmpSectionBlocks &&) = default; OmpSectionBlocks &operator=(OmpSectionBlocks &&) = default; OmpSectionBlocks(const OmpSectionBlocks &) = delete; OmpSectionBlocks &operator=(const OmpSectionBlocks &) = delete; OmpSectionBlocks() = delete; OmpSectionBlocks(std::list<Block> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::list<Block> v; };

struct OpenMPSectionsConstruct {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> OpenMPSectionsConstruct(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; OpenMPSectionsConstruct(OpenMPSectionsConstruct &&) = default; OpenMPSectionsConstruct &operator=(OpenMPSectionsConstruct &&) = default; OpenMPSectionsConstruct(const OpenMPSectionsConstruct &) = delete; OpenMPSectionsConstruct &operator=(const OpenMPSectionsConstruct &) = delete; OpenMPSectionsConstruct() = delete;
  std::tuple<OmpBeginSectionsDirective, OmpSectionBlocks,
      OmpEndSectionsDirective>
      t;
};


struct OmpBlockDirective {
  OmpBlockDirective(OmpBlockDirective &&) = default; OmpBlockDirective &operator=(OmpBlockDirective &&) = default; OmpBlockDirective(const OmpBlockDirective &) = delete; OmpBlockDirective &operator=(const OmpBlockDirective &) = delete; OmpBlockDirective() = delete; OmpBlockDirective(llvm::omp::Directive &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; llvm::omp::Directive v;
  CharBlock source;
};




struct OmpDeclareTargetWithList {
  OmpDeclareTargetWithList(OmpDeclareTargetWithList &&) = default; OmpDeclareTargetWithList &operator=(OmpDeclareTargetWithList &&) = default; OmpDeclareTargetWithList(const OmpDeclareTargetWithList &) = delete; OmpDeclareTargetWithList &operator=(const OmpDeclareTargetWithList &) = delete; OmpDeclareTargetWithList() = delete; OmpDeclareTargetWithList(OmpObjectList &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; OmpObjectList v;
  CharBlock source;
};

struct OmpDeclareTargetWithClause {
  OmpDeclareTargetWithClause(OmpDeclareTargetWithClause &&) = default; OmpDeclareTargetWithClause &operator=(OmpDeclareTargetWithClause &&) = default; OmpDeclareTargetWithClause(const OmpDeclareTargetWithClause &) = delete; OmpDeclareTargetWithClause &operator=(const OmpDeclareTargetWithClause &) = delete; OmpDeclareTargetWithClause() = delete; OmpDeclareTargetWithClause(OmpClauseList &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; OmpClauseList v;
  CharBlock source;
};

struct OmpDeclareTargetSpecifier {
  template <typename A, typename = common::NoLvalue<A>> OmpDeclareTargetSpecifier(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; OmpDeclareTargetSpecifier(OmpDeclareTargetSpecifier &&) = default; OmpDeclareTargetSpecifier &operator=(OmpDeclareTargetSpecifier &&) = default; OmpDeclareTargetSpecifier(const OmpDeclareTargetSpecifier &) = delete; OmpDeclareTargetSpecifier &operator=(const OmpDeclareTargetSpecifier &) = delete; OmpDeclareTargetSpecifier() = delete;
  std::variant<OmpDeclareTargetWithList, OmpDeclareTargetWithClause> u;
};

struct OpenMPDeclareTargetConstruct {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> OpenMPDeclareTargetConstruct(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; OpenMPDeclareTargetConstruct(OpenMPDeclareTargetConstruct &&) = default; OpenMPDeclareTargetConstruct &operator=(OpenMPDeclareTargetConstruct &&) = default; OpenMPDeclareTargetConstruct(const OpenMPDeclareTargetConstruct &) = delete; OpenMPDeclareTargetConstruct &operator=(const OpenMPDeclareTargetConstruct &) = delete; OpenMPDeclareTargetConstruct() = delete;
  CharBlock source;
  std::tuple<Verbatim, OmpDeclareTargetSpecifier> t;
};



struct OmpReductionCombiner {
  template <typename A, typename = common::NoLvalue<A>> OmpReductionCombiner(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; OmpReductionCombiner(OmpReductionCombiner &&) = default; OmpReductionCombiner &operator=(OmpReductionCombiner &&) = default; OmpReductionCombiner(const OmpReductionCombiner &) = delete; OmpReductionCombiner &operator=(const OmpReductionCombiner &) = delete; OmpReductionCombiner() = delete;
  struct FunctionCombiner { FunctionCombiner(FunctionCombiner &&) = default; FunctionCombiner &operator=(FunctionCombiner &&) = default; FunctionCombiner(const FunctionCombiner &) = delete; FunctionCombiner &operator=(const FunctionCombiner &) = delete; FunctionCombiner() = delete; FunctionCombiner(Call &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; Call v; };
  std::variant<AssignmentStmt, FunctionCombiner> u;
};

struct OmpReductionInitializerClause { OmpReductionInitializerClause(OmpReductionInitializerClause &&) = default; OmpReductionInitializerClause &operator=(OmpReductionInitializerClause &&) = default; OmpReductionInitializerClause(const OmpReductionInitializerClause &) = delete; OmpReductionInitializerClause &operator=(const OmpReductionInitializerClause &) = delete; OmpReductionInitializerClause() = delete; OmpReductionInitializerClause(Expr &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; Expr v; };

struct OpenMPDeclareReductionConstruct {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> OpenMPDeclareReductionConstruct(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; OpenMPDeclareReductionConstruct(OpenMPDeclareReductionConstruct &&) = default; OpenMPDeclareReductionConstruct &operator=(OpenMPDeclareReductionConstruct &&) = default; OpenMPDeclareReductionConstruct(const OpenMPDeclareReductionConstruct &) = delete; OpenMPDeclareReductionConstruct &operator=(const OpenMPDeclareReductionConstruct &) = delete; OpenMPDeclareReductionConstruct() = delete;
  CharBlock source;
  std::tuple<Verbatim, OmpReductionOperator, std::list<DeclarationTypeSpec>,
      OmpReductionCombiner, std::optional<OmpReductionInitializerClause>>
      t;
};



struct OpenMPDeclareSimdConstruct {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> OpenMPDeclareSimdConstruct(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; OpenMPDeclareSimdConstruct(OpenMPDeclareSimdConstruct &&) = default; OpenMPDeclareSimdConstruct &operator=(OpenMPDeclareSimdConstruct &&) = default; OpenMPDeclareSimdConstruct(const OpenMPDeclareSimdConstruct &) = delete; OpenMPDeclareSimdConstruct &operator=(const OpenMPDeclareSimdConstruct &) = delete; OpenMPDeclareSimdConstruct() = delete;
  CharBlock source;
  std::tuple<Verbatim, std::optional<Name>, OmpClauseList> t;
};


struct OpenMPThreadprivate {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> OpenMPThreadprivate(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; OpenMPThreadprivate(OpenMPThreadprivate &&) = default; OpenMPThreadprivate &operator=(OpenMPThreadprivate &&) = default; OpenMPThreadprivate(const OpenMPThreadprivate &) = delete; OpenMPThreadprivate &operator=(const OpenMPThreadprivate &) = delete; OpenMPThreadprivate() = delete;
  CharBlock source;
  std::tuple<Verbatim, OmpObjectList> t;
};

struct OpenMPDeclarativeConstruct {
  template <typename A, typename = common::NoLvalue<A>> OpenMPDeclarativeConstruct(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; OpenMPDeclarativeConstruct(OpenMPDeclarativeConstruct &&) = default; OpenMPDeclarativeConstruct &operator=(OpenMPDeclarativeConstruct &&) = default; OpenMPDeclarativeConstruct(const OpenMPDeclarativeConstruct &) = delete; OpenMPDeclarativeConstruct &operator=(const OpenMPDeclarativeConstruct &) = delete; OpenMPDeclarativeConstruct() = delete;
  CharBlock source;
  std::variant<OpenMPDeclareReductionConstruct, OpenMPDeclareSimdConstruct,
      OpenMPDeclareTargetConstruct, OpenMPThreadprivate>
      u;
};


struct OmpCriticalDirective {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> OmpCriticalDirective(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; OmpCriticalDirective(OmpCriticalDirective &&) = default; OmpCriticalDirective &operator=(OmpCriticalDirective &&) = default; OmpCriticalDirective(const OmpCriticalDirective &) = delete; OmpCriticalDirective &operator=(const OmpCriticalDirective &) = delete; OmpCriticalDirective() = delete;
  struct Hint { Hint(Hint &&) = default; Hint &operator=(Hint &&) = default; Hint(const Hint &) = delete; Hint &operator=(const Hint &) = delete; Hint() = delete; Hint(ConstantExpr &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; ConstantExpr v; };
  CharBlock source;
  std::tuple<Verbatim, std::optional<Name>, std::optional<Hint>> t;
};
struct OmpEndCriticalDirective {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> OmpEndCriticalDirective(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; OmpEndCriticalDirective(OmpEndCriticalDirective &&) = default; OmpEndCriticalDirective &operator=(OmpEndCriticalDirective &&) = default; OmpEndCriticalDirective(const OmpEndCriticalDirective &) = delete; OmpEndCriticalDirective &operator=(const OmpEndCriticalDirective &) = delete; OmpEndCriticalDirective() = delete;
  CharBlock source;
  std::tuple<Verbatim, std::optional<Name>> t;
};
struct OpenMPCriticalConstruct {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> OpenMPCriticalConstruct(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; OpenMPCriticalConstruct(OpenMPCriticalConstruct &&) = default; OpenMPCriticalConstruct &operator=(OpenMPCriticalConstruct &&) = default; OpenMPCriticalConstruct(const OpenMPCriticalConstruct &) = delete; OpenMPCriticalConstruct &operator=(const OpenMPCriticalConstruct &) = delete; OpenMPCriticalConstruct() = delete;
  std::tuple<OmpCriticalDirective, Block, OmpEndCriticalDirective> t;
};






struct OmpEndAtomic { OmpEndAtomic() {} OmpEndAtomic(const OmpEndAtomic &) {} OmpEndAtomic(OmpEndAtomic &&) {} OmpEndAtomic &operator=(const OmpEndAtomic &) { return *this; }; OmpEndAtomic &operator=(OmpEndAtomic &&) { return *this; }; using EmptyTrait = std::true_type; };


struct OmpMemoryClause {
  ENUM_CLASS(MemoryOrder, SeqCst)
  OmpMemoryClause(OmpMemoryClause &&) = default; OmpMemoryClause &operator=(OmpMemoryClause &&) = default; OmpMemoryClause(const OmpMemoryClause &) = delete; OmpMemoryClause &operator=(const OmpMemoryClause &) = delete; OmpMemoryClause() = delete; OmpMemoryClause(MemoryOrder &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; MemoryOrder v;
  CharBlock source;
};

struct OmpMemoryClauseList { OmpMemoryClauseList(OmpMemoryClauseList &&) = default; OmpMemoryClauseList &operator=(OmpMemoryClauseList &&) = default; OmpMemoryClauseList(const OmpMemoryClauseList &) = delete; OmpMemoryClauseList &operator=(const OmpMemoryClauseList &) = delete; OmpMemoryClauseList() = delete; OmpMemoryClauseList(std::list<OmpMemoryClause> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::list<OmpMemoryClause> v; };
struct OmpMemoryClausePostList { OmpMemoryClausePostList(OmpMemoryClausePostList &&) = default; OmpMemoryClausePostList &operator=(OmpMemoryClausePostList &&) = default; OmpMemoryClausePostList(const OmpMemoryClausePostList &) = delete; OmpMemoryClausePostList &operator=(const OmpMemoryClausePostList &) = delete; OmpMemoryClausePostList() = delete; OmpMemoryClausePostList(std::list<OmpMemoryClause> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::list<OmpMemoryClause> v; };


struct OmpAtomicRead {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> OmpAtomicRead(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; OmpAtomicRead(OmpAtomicRead &&) = default; OmpAtomicRead &operator=(OmpAtomicRead &&) = default; OmpAtomicRead(const OmpAtomicRead &) = delete; OmpAtomicRead &operator=(const OmpAtomicRead &) = delete; OmpAtomicRead() = delete;
  std::tuple<OmpMemoryClauseList, Verbatim, OmpMemoryClausePostList,
      Statement<AssignmentStmt>, std::optional<OmpEndAtomic>>
      t;
};


struct OmpAtomicWrite {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> OmpAtomicWrite(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; OmpAtomicWrite(OmpAtomicWrite &&) = default; OmpAtomicWrite &operator=(OmpAtomicWrite &&) = default; OmpAtomicWrite(const OmpAtomicWrite &) = delete; OmpAtomicWrite &operator=(const OmpAtomicWrite &) = delete; OmpAtomicWrite() = delete;
  std::tuple<OmpMemoryClauseList, Verbatim, OmpMemoryClausePostList,
      Statement<AssignmentStmt>, std::optional<OmpEndAtomic>>
      t;
};


struct OmpAtomicUpdate {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> OmpAtomicUpdate(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; OmpAtomicUpdate(OmpAtomicUpdate &&) = default; OmpAtomicUpdate &operator=(OmpAtomicUpdate &&) = default; OmpAtomicUpdate(const OmpAtomicUpdate &) = delete; OmpAtomicUpdate &operator=(const OmpAtomicUpdate &) = delete; OmpAtomicUpdate() = delete;
  std::tuple<OmpMemoryClauseList, Verbatim, OmpMemoryClausePostList,
      Statement<AssignmentStmt>, std::optional<OmpEndAtomic>>
      t;
};


struct OmpAtomicCapture {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> OmpAtomicCapture(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; OmpAtomicCapture(OmpAtomicCapture &&) = default; OmpAtomicCapture &operator=(OmpAtomicCapture &&) = default; OmpAtomicCapture(const OmpAtomicCapture &) = delete; OmpAtomicCapture &operator=(const OmpAtomicCapture &) = delete; OmpAtomicCapture() = delete;
  struct Stmt1 { Stmt1(Stmt1 &&) = default; Stmt1 &operator=(Stmt1 &&) = default; Stmt1(const Stmt1 &) = delete; Stmt1 &operator=(const Stmt1 &) = delete; Stmt1() = delete; Stmt1(Statement<AssignmentStmt> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; Statement<AssignmentStmt> v; };
  struct Stmt2 { Stmt2(Stmt2 &&) = default; Stmt2 &operator=(Stmt2 &&) = default; Stmt2(const Stmt2 &) = delete; Stmt2 &operator=(const Stmt2 &) = delete; Stmt2() = delete; Stmt2(Statement<AssignmentStmt> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; Statement<AssignmentStmt> v; };
  std::tuple<OmpMemoryClauseList, Verbatim, OmpMemoryClausePostList, Stmt1,
      Stmt2, OmpEndAtomic>
      t;
};


struct OmpAtomic {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> OmpAtomic(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; OmpAtomic(OmpAtomic &&) = default; OmpAtomic &operator=(OmpAtomic &&) = default; OmpAtomic(const OmpAtomic &) = delete; OmpAtomic &operator=(const OmpAtomic &) = delete; OmpAtomic() = delete;
  std::tuple<Verbatim, OmpMemoryClauseList, Statement<AssignmentStmt>,
      std::optional<OmpEndAtomic>>
      t;
};

struct OpenMPAtomicConstruct {
  template <typename A, typename = common::NoLvalue<A>> OpenMPAtomicConstruct(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; OpenMPAtomicConstruct(OpenMPAtomicConstruct &&) = default; OpenMPAtomicConstruct &operator=(OpenMPAtomicConstruct &&) = default; OpenMPAtomicConstruct(const OpenMPAtomicConstruct &) = delete; OpenMPAtomicConstruct &operator=(const OpenMPAtomicConstruct &) = delete; OpenMPAtomicConstruct() = delete;
  std::variant<OmpAtomicRead, OmpAtomicWrite, OmpAtomicCapture, OmpAtomicUpdate,
      OmpAtomic>
      u;
};


struct OmpLoopDirective {
  OmpLoopDirective(OmpLoopDirective &&) = default; OmpLoopDirective &operator=(OmpLoopDirective &&) = default; OmpLoopDirective(const OmpLoopDirective &) = delete; OmpLoopDirective &operator=(const OmpLoopDirective &) = delete; OmpLoopDirective() = delete; OmpLoopDirective(llvm::omp::Directive &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; llvm::omp::Directive v;
  CharBlock source;
};


struct OmpCancelType {
  ENUM_CLASS(Type, Parallel, Sections, Do, Taskgroup)
  OmpCancelType(OmpCancelType &&) = default; OmpCancelType &operator=(OmpCancelType &&) = default; OmpCancelType(const OmpCancelType &) = delete; OmpCancelType &operator=(const OmpCancelType &) = delete; OmpCancelType() = delete; OmpCancelType(Type &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; Type v;
  CharBlock source;
};


struct OpenMPCancellationPointConstruct {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> OpenMPCancellationPointConstruct(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; OpenMPCancellationPointConstruct(OpenMPCancellationPointConstruct &&) = default; OpenMPCancellationPointConstruct &operator=(OpenMPCancellationPointConstruct &&) = default; OpenMPCancellationPointConstruct(const OpenMPCancellationPointConstruct &) = delete; OpenMPCancellationPointConstruct &operator=(const OpenMPCancellationPointConstruct &) = delete; OpenMPCancellationPointConstruct() = delete;
  CharBlock source;
  std::tuple<Verbatim, OmpCancelType> t;
};


struct OpenMPCancelConstruct {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> OpenMPCancelConstruct(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; OpenMPCancelConstruct(OpenMPCancelConstruct &&) = default; OpenMPCancelConstruct &operator=(OpenMPCancelConstruct &&) = default; OpenMPCancelConstruct(const OpenMPCancelConstruct &) = delete; OpenMPCancelConstruct &operator=(const OpenMPCancelConstruct &) = delete; OpenMPCancelConstruct() = delete;
  struct If { If(If &&) = default; If &operator=(If &&) = default; If(const If &) = delete; If &operator=(const If &) = delete; If() = delete; If(ScalarLogicalExpr &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; ScalarLogicalExpr v; };
  CharBlock source;
  std::tuple<Verbatim, OmpCancelType, std::optional<If>> t;
};





struct OmpFlushMemoryClause {
  ENUM_CLASS(FlushMemoryOrder, AcqRel, Release, Acquire)
  OmpFlushMemoryClause(OmpFlushMemoryClause &&) = default; OmpFlushMemoryClause &operator=(OmpFlushMemoryClause &&) = default; OmpFlushMemoryClause(const OmpFlushMemoryClause &) = delete; OmpFlushMemoryClause &operator=(const OmpFlushMemoryClause &) = delete; OmpFlushMemoryClause() = delete; OmpFlushMemoryClause(FlushMemoryOrder &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; FlushMemoryOrder v;
  CharBlock source;
};


struct OpenMPFlushConstruct {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> OpenMPFlushConstruct(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; OpenMPFlushConstruct(OpenMPFlushConstruct &&) = default; OpenMPFlushConstruct &operator=(OpenMPFlushConstruct &&) = default; OpenMPFlushConstruct(const OpenMPFlushConstruct &) = delete; OpenMPFlushConstruct &operator=(const OpenMPFlushConstruct &) = delete; OpenMPFlushConstruct() = delete;
  CharBlock source;
  std::tuple<Verbatim, std::optional<OmpFlushMemoryClause>,
      std::optional<OmpObjectList>>
      t;
};

struct OmpSimpleStandaloneDirective {
  OmpSimpleStandaloneDirective(OmpSimpleStandaloneDirective &&) = default; OmpSimpleStandaloneDirective &operator=(OmpSimpleStandaloneDirective &&) = default; OmpSimpleStandaloneDirective(const OmpSimpleStandaloneDirective &) = delete; OmpSimpleStandaloneDirective &operator=(const OmpSimpleStandaloneDirective &) = delete; OmpSimpleStandaloneDirective() = delete; OmpSimpleStandaloneDirective(llvm::omp::Directive &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; llvm::omp::Directive v;
  CharBlock source;
};

struct OpenMPSimpleStandaloneConstruct {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> OpenMPSimpleStandaloneConstruct(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; OpenMPSimpleStandaloneConstruct(OpenMPSimpleStandaloneConstruct &&) = default; OpenMPSimpleStandaloneConstruct &operator=(OpenMPSimpleStandaloneConstruct &&) = default; OpenMPSimpleStandaloneConstruct(const OpenMPSimpleStandaloneConstruct &) = delete; OpenMPSimpleStandaloneConstruct &operator=(const OpenMPSimpleStandaloneConstruct &) = delete; OpenMPSimpleStandaloneConstruct() = delete;
  CharBlock source;
  std::tuple<OmpSimpleStandaloneDirective, OmpClauseList> t;
};

struct OpenMPStandaloneConstruct {
  template <typename A, typename = common::NoLvalue<A>> OpenMPStandaloneConstruct(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; OpenMPStandaloneConstruct(OpenMPStandaloneConstruct &&) = default; OpenMPStandaloneConstruct &operator=(OpenMPStandaloneConstruct &&) = default; OpenMPStandaloneConstruct(const OpenMPStandaloneConstruct &) = delete; OpenMPStandaloneConstruct &operator=(const OpenMPStandaloneConstruct &) = delete; OpenMPStandaloneConstruct() = delete;
  CharBlock source;
  std::variant<OpenMPSimpleStandaloneConstruct, OpenMPFlushConstruct,
      OpenMPCancelConstruct, OpenMPCancellationPointConstruct>
      u;
};

struct OmpBeginLoopDirective {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> OmpBeginLoopDirective(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; OmpBeginLoopDirective(OmpBeginLoopDirective &&) = default; OmpBeginLoopDirective &operator=(OmpBeginLoopDirective &&) = default; OmpBeginLoopDirective(const OmpBeginLoopDirective &) = delete; OmpBeginLoopDirective &operator=(const OmpBeginLoopDirective &) = delete; OmpBeginLoopDirective() = delete;
  std::tuple<OmpLoopDirective, OmpClauseList> t;
  CharBlock source;
};

struct OmpEndLoopDirective {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> OmpEndLoopDirective(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; OmpEndLoopDirective(OmpEndLoopDirective &&) = default; OmpEndLoopDirective &operator=(OmpEndLoopDirective &&) = default; OmpEndLoopDirective(const OmpEndLoopDirective &) = delete; OmpEndLoopDirective &operator=(const OmpEndLoopDirective &) = delete; OmpEndLoopDirective() = delete;
  std::tuple<OmpLoopDirective, OmpClauseList> t;
  CharBlock source;
};

struct OmpBeginBlockDirective {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> OmpBeginBlockDirective(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; OmpBeginBlockDirective(OmpBeginBlockDirective &&) = default; OmpBeginBlockDirective &operator=(OmpBeginBlockDirective &&) = default; OmpBeginBlockDirective(const OmpBeginBlockDirective &) = delete; OmpBeginBlockDirective &operator=(const OmpBeginBlockDirective &) = delete; OmpBeginBlockDirective() = delete;
  std::tuple<OmpBlockDirective, OmpClauseList> t;
  CharBlock source;
};

struct OmpEndBlockDirective {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> OmpEndBlockDirective(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; OmpEndBlockDirective(OmpEndBlockDirective &&) = default; OmpEndBlockDirective &operator=(OmpEndBlockDirective &&) = default; OmpEndBlockDirective(const OmpEndBlockDirective &) = delete; OmpEndBlockDirective &operator=(const OmpEndBlockDirective &) = delete; OmpEndBlockDirective() = delete;
  std::tuple<OmpBlockDirective, OmpClauseList> t;
  CharBlock source;
};

struct OpenMPBlockConstruct {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> OpenMPBlockConstruct(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; OpenMPBlockConstruct(OpenMPBlockConstruct &&) = default; OpenMPBlockConstruct &operator=(OpenMPBlockConstruct &&) = default; OpenMPBlockConstruct(const OpenMPBlockConstruct &) = delete; OpenMPBlockConstruct &operator=(const OpenMPBlockConstruct &) = delete; OpenMPBlockConstruct() = delete;
  std::tuple<OmpBeginBlockDirective, Block, OmpEndBlockDirective> t;
};


struct OpenMPLoopConstruct {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> OpenMPLoopConstruct(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; OpenMPLoopConstruct(OpenMPLoopConstruct &&) = default; OpenMPLoopConstruct &operator=(OpenMPLoopConstruct &&) = default; OpenMPLoopConstruct(const OpenMPLoopConstruct &) = delete; OpenMPLoopConstruct &operator=(const OpenMPLoopConstruct &) = delete; OpenMPLoopConstruct() = delete;
  OpenMPLoopConstruct(OmpBeginLoopDirective &&a)
      : t({std::move(a), std::nullopt, std::nullopt}) {}
  std::tuple<OmpBeginLoopDirective, std::optional<DoConstruct>,
      std::optional<OmpEndLoopDirective>>
      t;
};

struct OpenMPConstruct {
  template <typename A, typename = common::NoLvalue<A>> OpenMPConstruct(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; OpenMPConstruct(OpenMPConstruct &&) = default; OpenMPConstruct &operator=(OpenMPConstruct &&) = default; OpenMPConstruct(const OpenMPConstruct &) = delete; OpenMPConstruct &operator=(const OpenMPConstruct &) = delete; OpenMPConstruct() = delete;
  std::variant<OpenMPStandaloneConstruct, OpenMPSectionsConstruct,
      OpenMPLoopConstruct, OpenMPBlockConstruct, OpenMPAtomicConstruct,
      OpenMPCriticalConstruct>
      u;
};



struct AccObject {
  template <typename A, typename = common::NoLvalue<A>> AccObject(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; AccObject(AccObject &&) = default; AccObject &operator=(AccObject &&) = default; AccObject(const AccObject &) = delete; AccObject &operator=(const AccObject &) = delete; AccObject() = delete;
  std::variant<Designator, Name> u;
};

struct AccObjectList { AccObjectList(AccObjectList &&) = default; AccObjectList &operator=(AccObjectList &&) = default; AccObjectList(const AccObjectList &) = delete; AccObjectList &operator=(const AccObjectList &) = delete; AccObjectList() = delete; AccObjectList(std::list<AccObject> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::list<AccObject> v; };


struct AccBlockDirective {
  AccBlockDirective(AccBlockDirective &&) = default; AccBlockDirective &operator=(AccBlockDirective &&) = default; AccBlockDirective(const AccBlockDirective &) = delete; AccBlockDirective &operator=(const AccBlockDirective &) = delete; AccBlockDirective() = delete; AccBlockDirective(llvm::acc::Directive &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; llvm::acc::Directive v;
  CharBlock source;
};

struct AccLoopDirective {
  AccLoopDirective(AccLoopDirective &&) = default; AccLoopDirective &operator=(AccLoopDirective &&) = default; AccLoopDirective(const AccLoopDirective &) = delete; AccLoopDirective &operator=(const AccLoopDirective &) = delete; AccLoopDirective() = delete; AccLoopDirective(llvm::acc::Directive &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; llvm::acc::Directive v;
  CharBlock source;
};

struct AccStandaloneDirective {
  AccStandaloneDirective(AccStandaloneDirective &&) = default; AccStandaloneDirective &operator=(AccStandaloneDirective &&) = default; AccStandaloneDirective(const AccStandaloneDirective &) = delete; AccStandaloneDirective &operator=(const AccStandaloneDirective &) = delete; AccStandaloneDirective() = delete; AccStandaloneDirective(llvm::acc::Directive &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; llvm::acc::Directive v;
  CharBlock source;
};


struct AccCombinedDirective {
  AccCombinedDirective(AccCombinedDirective &&) = default; AccCombinedDirective &operator=(AccCombinedDirective &&) = default; AccCombinedDirective(const AccCombinedDirective &) = delete; AccCombinedDirective &operator=(const AccCombinedDirective &) = delete; AccCombinedDirective() = delete; AccCombinedDirective(llvm::acc::Directive &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; llvm::acc::Directive v;
  CharBlock source;
};

struct AccDeclarativeDirective {
  AccDeclarativeDirective(AccDeclarativeDirective &&) = default; AccDeclarativeDirective &operator=(AccDeclarativeDirective &&) = default; AccDeclarativeDirective(const AccDeclarativeDirective &) = delete; AccDeclarativeDirective &operator=(const AccDeclarativeDirective &) = delete; AccDeclarativeDirective() = delete; AccDeclarativeDirective(llvm::acc::Directive &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; llvm::acc::Directive v;
  CharBlock source;
};


struct AccDefaultClause {
  ENUM_CLASS(Arg, None, Present)
  AccDefaultClause(AccDefaultClause &&) = default; AccDefaultClause &operator=(AccDefaultClause &&) = default; AccDefaultClause(const AccDefaultClause &) = delete; AccDefaultClause &operator=(const AccDefaultClause &) = delete; AccDefaultClause() = delete; AccDefaultClause(Arg &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; Arg v;
  CharBlock source;
};

struct AccDataModifier {
  ENUM_CLASS(Modifier, ReadOnly, Zero)
  AccDataModifier(AccDataModifier &&) = default; AccDataModifier &operator=(AccDataModifier &&) = default; AccDataModifier(const AccDataModifier &) = delete; AccDataModifier &operator=(const AccDataModifier &) = delete; AccDataModifier() = delete; AccDataModifier(Modifier &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; Modifier v;
  CharBlock source;
};

struct AccObjectListWithModifier {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> AccObjectListWithModifier(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; AccObjectListWithModifier(AccObjectListWithModifier &&) = default; AccObjectListWithModifier &operator=(AccObjectListWithModifier &&) = default; AccObjectListWithModifier(const AccObjectListWithModifier &) = delete; AccObjectListWithModifier &operator=(const AccObjectListWithModifier &) = delete; AccObjectListWithModifier() = delete;
  std::tuple<std::optional<AccDataModifier>, AccObjectList> t;
};


struct AccReductionOperator {
  template <typename A, typename = common::NoLvalue<A>> AccReductionOperator(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; AccReductionOperator(AccReductionOperator &&) = default; AccReductionOperator &operator=(AccReductionOperator &&) = default; AccReductionOperator(const AccReductionOperator &) = delete; AccReductionOperator &operator=(const AccReductionOperator &) = delete; AccReductionOperator() = delete;
  std::variant<DefinedOperator, ProcedureDesignator> u;
};

struct AccObjectListWithReduction {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> AccObjectListWithReduction(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; AccObjectListWithReduction(AccObjectListWithReduction &&) = default; AccObjectListWithReduction &operator=(AccObjectListWithReduction &&) = default; AccObjectListWithReduction(const AccObjectListWithReduction &) = delete; AccObjectListWithReduction &operator=(const AccObjectListWithReduction &) = delete; AccObjectListWithReduction() = delete;
  std::tuple<AccReductionOperator, AccObjectList> t;
};

struct AccWaitArgument {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> AccWaitArgument(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; AccWaitArgument(AccWaitArgument &&) = default; AccWaitArgument &operator=(AccWaitArgument &&) = default; AccWaitArgument(const AccWaitArgument &) = delete; AccWaitArgument &operator=(const AccWaitArgument &) = delete; AccWaitArgument() = delete;
  std::tuple<std::optional<ScalarIntExpr>, std::list<ScalarIntExpr>> t;
};

struct AccSizeExpr {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> AccSizeExpr(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; AccSizeExpr(AccSizeExpr &&) = default; AccSizeExpr &operator=(AccSizeExpr &&) = default; AccSizeExpr(const AccSizeExpr &) = delete; AccSizeExpr &operator=(const AccSizeExpr &) = delete; AccSizeExpr() = delete;
  CharBlock source;
  std::tuple<std::optional<ScalarIntExpr>> t;
};

struct AccSizeExprList {
  AccSizeExprList(AccSizeExprList &&) = default; AccSizeExprList &operator=(AccSizeExprList &&) = default; AccSizeExprList(const AccSizeExprList &) = delete; AccSizeExprList &operator=(const AccSizeExprList &) = delete; AccSizeExprList() = delete; AccSizeExprList(std::list<AccSizeExpr> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::list<AccSizeExpr> v;
};

struct AccGangArgument {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> AccGangArgument(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; AccGangArgument(AccGangArgument &&) = default; AccGangArgument &operator=(AccGangArgument &&) = default; AccGangArgument(const AccGangArgument &) = delete; AccGangArgument &operator=(const AccGangArgument &) = delete; AccGangArgument() = delete;
  std::tuple<std::optional<ScalarIntExpr>, std::optional<AccSizeExpr>> t;
};

struct AccClause {
  template <typename A, typename = common::NoLvalue<A>> AccClause(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; AccClause(AccClause &&) = default; AccClause &operator=(AccClause &&) = default; AccClause(const AccClause &) = delete; AccClause &operator=(const AccClause &) = delete; AccClause() = delete;



  CharBlock source;

  std::variant<

      >
      u;
};

struct AccClauseList {
  AccClauseList(AccClauseList &&) = default; AccClauseList &operator=(AccClauseList &&) = default; AccClauseList(const AccClauseList &) = delete; AccClauseList &operator=(const AccClauseList &) = delete; AccClauseList() = delete; AccClauseList(std::list<AccClause> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; std::list<AccClause> v;
  CharBlock source;
};

struct OpenACCRoutineConstruct {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> OpenACCRoutineConstruct(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; OpenACCRoutineConstruct(OpenACCRoutineConstruct &&) = default; OpenACCRoutineConstruct &operator=(OpenACCRoutineConstruct &&) = default; OpenACCRoutineConstruct(const OpenACCRoutineConstruct &) = delete; OpenACCRoutineConstruct &operator=(const OpenACCRoutineConstruct &) = delete; OpenACCRoutineConstruct() = delete;
  CharBlock source;
  std::tuple<Verbatim, std::optional<Name>, AccClauseList> t;
};

struct OpenACCCacheConstruct {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> OpenACCCacheConstruct(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; OpenACCCacheConstruct(OpenACCCacheConstruct &&) = default; OpenACCCacheConstruct &operator=(OpenACCCacheConstruct &&) = default; OpenACCCacheConstruct(const OpenACCCacheConstruct &) = delete; OpenACCCacheConstruct &operator=(const OpenACCCacheConstruct &) = delete; OpenACCCacheConstruct() = delete;
  CharBlock source;
  std::tuple<Verbatim, AccObjectListWithModifier> t;
};

struct OpenACCWaitConstruct {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> OpenACCWaitConstruct(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; OpenACCWaitConstruct(OpenACCWaitConstruct &&) = default; OpenACCWaitConstruct &operator=(OpenACCWaitConstruct &&) = default; OpenACCWaitConstruct(const OpenACCWaitConstruct &) = delete; OpenACCWaitConstruct &operator=(const OpenACCWaitConstruct &) = delete; OpenACCWaitConstruct() = delete;
  CharBlock source;
  std::tuple<Verbatim, std::optional<AccWaitArgument>, AccClauseList> t;
};

struct AccBeginLoopDirective {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> AccBeginLoopDirective(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; AccBeginLoopDirective(AccBeginLoopDirective &&) = default; AccBeginLoopDirective &operator=(AccBeginLoopDirective &&) = default; AccBeginLoopDirective(const AccBeginLoopDirective &) = delete; AccBeginLoopDirective &operator=(const AccBeginLoopDirective &) = delete; AccBeginLoopDirective() = delete;
  std::tuple<AccLoopDirective, AccClauseList> t;
  CharBlock source;
};

struct AccBeginBlockDirective {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> AccBeginBlockDirective(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; AccBeginBlockDirective(AccBeginBlockDirective &&) = default; AccBeginBlockDirective &operator=(AccBeginBlockDirective &&) = default; AccBeginBlockDirective(const AccBeginBlockDirective &) = delete; AccBeginBlockDirective &operator=(const AccBeginBlockDirective &) = delete; AccBeginBlockDirective() = delete;
  CharBlock source;
  std::tuple<AccBlockDirective, AccClauseList> t;
};

struct AccEndBlockDirective {
  CharBlock source;
  AccEndBlockDirective(AccEndBlockDirective &&) = default; AccEndBlockDirective &operator=(AccEndBlockDirective &&) = default; AccEndBlockDirective(const AccEndBlockDirective &) = delete; AccEndBlockDirective &operator=(const AccEndBlockDirective &) = delete; AccEndBlockDirective() = delete; AccEndBlockDirective(AccBlockDirective &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; AccBlockDirective v;
};


struct AccEndAtomic { AccEndAtomic() {} AccEndAtomic(const AccEndAtomic &) {} AccEndAtomic(AccEndAtomic &&) {} AccEndAtomic &operator=(const AccEndAtomic &) { return *this; }; AccEndAtomic &operator=(AccEndAtomic &&) { return *this; }; using EmptyTrait = std::true_type; };


struct AccAtomicRead {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> AccAtomicRead(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; AccAtomicRead(AccAtomicRead &&) = default; AccAtomicRead &operator=(AccAtomicRead &&) = default; AccAtomicRead(const AccAtomicRead &) = delete; AccAtomicRead &operator=(const AccAtomicRead &) = delete; AccAtomicRead() = delete;
  std::tuple<Verbatim, Statement<AssignmentStmt>, std::optional<AccEndAtomic>>
      t;
};


struct AccAtomicWrite {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> AccAtomicWrite(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; AccAtomicWrite(AccAtomicWrite &&) = default; AccAtomicWrite &operator=(AccAtomicWrite &&) = default; AccAtomicWrite(const AccAtomicWrite &) = delete; AccAtomicWrite &operator=(const AccAtomicWrite &) = delete; AccAtomicWrite() = delete;
  std::tuple<Verbatim, Statement<AssignmentStmt>, std::optional<AccEndAtomic>>
      t;
};


struct AccAtomicUpdate {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> AccAtomicUpdate(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; AccAtomicUpdate(AccAtomicUpdate &&) = default; AccAtomicUpdate &operator=(AccAtomicUpdate &&) = default; AccAtomicUpdate(const AccAtomicUpdate &) = delete; AccAtomicUpdate &operator=(const AccAtomicUpdate &) = delete; AccAtomicUpdate() = delete;
  std::tuple<std::optional<Verbatim>, Statement<AssignmentStmt>,
      std::optional<AccEndAtomic>>
      t;
};


struct AccAtomicCapture {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> AccAtomicCapture(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; AccAtomicCapture(AccAtomicCapture &&) = default; AccAtomicCapture &operator=(AccAtomicCapture &&) = default; AccAtomicCapture(const AccAtomicCapture &) = delete; AccAtomicCapture &operator=(const AccAtomicCapture &) = delete; AccAtomicCapture() = delete;
  struct Stmt1 { Stmt1(Stmt1 &&) = default; Stmt1 &operator=(Stmt1 &&) = default; Stmt1(const Stmt1 &) = delete; Stmt1 &operator=(const Stmt1 &) = delete; Stmt1() = delete; Stmt1(Statement<AssignmentStmt> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; Statement<AssignmentStmt> v; };
  struct Stmt2 { Stmt2(Stmt2 &&) = default; Stmt2 &operator=(Stmt2 &&) = default; Stmt2(const Stmt2 &) = delete; Stmt2 &operator=(const Stmt2 &) = delete; Stmt2() = delete; Stmt2(Statement<AssignmentStmt> &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; Statement<AssignmentStmt> v; };
  std::tuple<Verbatim, Stmt1, Stmt2, AccEndAtomic> t;
};

struct OpenACCAtomicConstruct {
  template <typename A, typename = common::NoLvalue<A>> OpenACCAtomicConstruct(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; OpenACCAtomicConstruct(OpenACCAtomicConstruct &&) = default; OpenACCAtomicConstruct &operator=(OpenACCAtomicConstruct &&) = default; OpenACCAtomicConstruct(const OpenACCAtomicConstruct &) = delete; OpenACCAtomicConstruct &operator=(const OpenACCAtomicConstruct &) = delete; OpenACCAtomicConstruct() = delete;
  std::variant<AccAtomicRead, AccAtomicWrite, AccAtomicCapture, AccAtomicUpdate>
      u;
};

struct OpenACCBlockConstruct {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> OpenACCBlockConstruct(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; OpenACCBlockConstruct(OpenACCBlockConstruct &&) = default; OpenACCBlockConstruct &operator=(OpenACCBlockConstruct &&) = default; OpenACCBlockConstruct(const OpenACCBlockConstruct &) = delete; OpenACCBlockConstruct &operator=(const OpenACCBlockConstruct &) = delete; OpenACCBlockConstruct() = delete;
  std::tuple<AccBeginBlockDirective, Block, AccEndBlockDirective> t;
};

struct OpenACCStandaloneDeclarativeConstruct {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> OpenACCStandaloneDeclarativeConstruct(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; OpenACCStandaloneDeclarativeConstruct(OpenACCStandaloneDeclarativeConstruct &&) = default; OpenACCStandaloneDeclarativeConstruct &operator=(OpenACCStandaloneDeclarativeConstruct &&) = default; OpenACCStandaloneDeclarativeConstruct(const OpenACCStandaloneDeclarativeConstruct &) = delete; OpenACCStandaloneDeclarativeConstruct &operator=(const OpenACCStandaloneDeclarativeConstruct &) = delete; OpenACCStandaloneDeclarativeConstruct() = delete;
  CharBlock source;
  std::tuple<AccDeclarativeDirective, AccClauseList> t;
};

struct AccBeginCombinedDirective {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> AccBeginCombinedDirective(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; AccBeginCombinedDirective(AccBeginCombinedDirective &&) = default; AccBeginCombinedDirective &operator=(AccBeginCombinedDirective &&) = default; AccBeginCombinedDirective(const AccBeginCombinedDirective &) = delete; AccBeginCombinedDirective &operator=(const AccBeginCombinedDirective &) = delete; AccBeginCombinedDirective() = delete;
  std::tuple<AccCombinedDirective, AccClauseList> t;
};

struct AccEndCombinedDirective {
  AccEndCombinedDirective(AccEndCombinedDirective &&) = default; AccEndCombinedDirective &operator=(AccEndCombinedDirective &&) = default; AccEndCombinedDirective(const AccEndCombinedDirective &) = delete; AccEndCombinedDirective &operator=(const AccEndCombinedDirective &) = delete; AccEndCombinedDirective() = delete; AccEndCombinedDirective(AccCombinedDirective &&x) : v(std::move(x)) {} using WrapperTrait = std::true_type; AccCombinedDirective v;
  CharBlock source;
};

struct OpenACCCombinedConstruct {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> OpenACCCombinedConstruct(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; OpenACCCombinedConstruct(OpenACCCombinedConstruct &&) = default; OpenACCCombinedConstruct &operator=(OpenACCCombinedConstruct &&) = default; OpenACCCombinedConstruct(const OpenACCCombinedConstruct &) = delete; OpenACCCombinedConstruct &operator=(const OpenACCCombinedConstruct &) = delete; OpenACCCombinedConstruct() = delete;
  CharBlock source;
  std::tuple<AccBeginCombinedDirective, Block,
      std::optional<AccEndCombinedDirective>>
      t;
};

struct OpenACCDeclarativeConstruct {
  template <typename A, typename = common::NoLvalue<A>> OpenACCDeclarativeConstruct(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; OpenACCDeclarativeConstruct(OpenACCDeclarativeConstruct &&) = default; OpenACCDeclarativeConstruct &operator=(OpenACCDeclarativeConstruct &&) = default; OpenACCDeclarativeConstruct(const OpenACCDeclarativeConstruct &) = delete; OpenACCDeclarativeConstruct &operator=(const OpenACCDeclarativeConstruct &) = delete; OpenACCDeclarativeConstruct() = delete;
  CharBlock source;
  std::variant<OpenACCStandaloneDeclarativeConstruct> u;
};


struct OpenACCLoopConstruct {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> OpenACCLoopConstruct(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; OpenACCLoopConstruct(OpenACCLoopConstruct &&) = default; OpenACCLoopConstruct &operator=(OpenACCLoopConstruct &&) = default; OpenACCLoopConstruct(const OpenACCLoopConstruct &) = delete; OpenACCLoopConstruct &operator=(const OpenACCLoopConstruct &) = delete; OpenACCLoopConstruct() = delete;
  OpenACCLoopConstruct(AccBeginLoopDirective &&a)
      : t({std::move(a), std::nullopt}) {}
  std::tuple<AccBeginLoopDirective, std::optional<DoConstruct>> t;
};

struct OpenACCStandaloneConstruct {
  template <typename... Ts, typename = common::NoLvalue<Ts...>> OpenACCStandaloneConstruct(Ts &&...args) : t(std::move(args)...) {} using TupleTrait = std::true_type; OpenACCStandaloneConstruct(OpenACCStandaloneConstruct &&) = default; OpenACCStandaloneConstruct &operator=(OpenACCStandaloneConstruct &&) = default; OpenACCStandaloneConstruct(const OpenACCStandaloneConstruct &) = delete; OpenACCStandaloneConstruct &operator=(const OpenACCStandaloneConstruct &) = delete; OpenACCStandaloneConstruct() = delete;
  CharBlock source;
  std::tuple<AccStandaloneDirective, AccClauseList> t;
};

struct OpenACCConstruct {
  template <typename A, typename = common::NoLvalue<A>> OpenACCConstruct(A &&x) : u(std::move(x)) {} using UnionTrait = std::true_type; OpenACCConstruct(OpenACCConstruct &&) = default; OpenACCConstruct &operator=(OpenACCConstruct &&) = default; OpenACCConstruct(const OpenACCConstruct &) = delete; OpenACCConstruct &operator=(const OpenACCConstruct &) = delete; OpenACCConstruct() = delete;
  std::variant<OpenACCBlockConstruct, OpenACCCombinedConstruct,
      OpenACCLoopConstruct, OpenACCStandaloneConstruct, OpenACCRoutineConstruct,
      OpenACCCacheConstruct, OpenACCWaitConstruct, OpenACCAtomicConstruct>
      u;
};

}
