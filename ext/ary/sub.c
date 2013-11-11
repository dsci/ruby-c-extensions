#include <sub.h>

VALUE subTest;

static VALUE t_foo(VALUE self){
  VALUE f;
  f = rb_str_new2("String");
  return f;
}

void Init_sub(VALUE parent){
  subTest = rb_define_class("MyChildTest", parent);

  rb_define_method(subTest, "foo", t_foo, 0);

  Init_sub_with_block(subTest);
}


