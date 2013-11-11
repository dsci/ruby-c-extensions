#include "ary.h"

/*
Will result in a class like that

class MyTest

  def initialize
    @arr = Array.new # or @arr = []
  end

  def add(obj)
    @arr.add(obj)
  end

  def remove(obj)
    @arr.delete(obj)
  end

  def own_method
    return "String"
  end

  def length_of_arr
    return @arr.size
  end

end
*/
static VALUE t_foo(VALUE self);

static VALUE t_init(VALUE self){
  VALUE arr;

  arr = rb_ary_new();
  rb_iv_set(self, "@arr",arr);

  return self;
}

static VALUE t_add(VALUE self, VALUE obj){
  VALUE arr;

  arr = rb_iv_get(self, "@arr");
  rb_funcall(arr, id_push, 1, obj);

  return arr;
}

static VALUE t_remove(VALUE self, VALUE obj){
  VALUE arr;

  arr = rb_iv_get(self, "@arr");
  rb_funcall(arr, id_remove, 1, obj);

  return arr;
}

static VALUE t_own_method(VALUE self){
  //const char *p = "String";
  VALUE str;
  str = rb_str_new2("String");

  return str;
}

static VALUE t_length_of_arr(VALUE self){
  VALUE size;
  VALUE arr;

  arr = rb_iv_get(self, "@arr");
  size = rb_funcall(arr, id_ary_size, 0);

  return size;

}

void Init_ary(){
  cTest = rb_define_class("MyTest", rb_cObject);
  //subTest = rb_define_class("MyChildTest", cTest);
  rb_define_method(cTest, "initialize", t_init, 0);
  rb_define_method(cTest, "add", t_add, 1);
  rb_define_method(cTest, "remove", t_remove,1);
  rb_define_method(cTest, "own_method", t_own_method, 0);
  rb_define_method(cTest, "length_of_arr", t_length_of_arr,0);

  //rb_define_method(subTest, "foo", t_foo, 0);
  Init_sub(cTest);

  id_push   = rb_intern("push");
  id_remove = rb_intern("delete");
  id_ary_size = rb_intern("size");
}