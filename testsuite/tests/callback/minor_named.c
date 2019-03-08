#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/callback.h>

value incr_ref(value unit) {
  static const value* v;
  if (!v) v = caml_named_value("incr_ref");
  caml_modify_field(*v, 0, Val_int(Int_field(*v, 0) + 1));
  return Val_unit;
}
