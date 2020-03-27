module Parse = {
  open Parser_flow;

  type loc_t = Loc.t;

  let parse_options =
    Parser_env.(
      Some({
        esproposal_class_instance_fields: true,
        esproposal_class_static_fields: true,
        esproposal_decorators: true,
        esproposal_export_star_as: true,
        types: true,
        use_strict: false,
        esproposal_optional_chaining: true,
        esproposal_nullish_coalescing: true,
        enums: true,
      })
    );

  type code = {src: string};
  type t = (code, Parser_flow.Ast.program(loc_t, loc_t));
  let parse = src => {
    let (ast, _) = Parser_flow.program(~fail=false, ~parse_options, src);
    let code = {
      src;
    };
    (code, ast);
  };
};

let _ = Parse.parse("let x = 1;");

print_endline("Hello World!");
