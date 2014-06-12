#include "sub_with_block.h"

VALUE subWithBlock;

static VALUE t_my_method(VALUE self){
  if(rb_block_given_p()){
    rb_yield(Qnil);
  }
  return Qnil;
}

static VALUE t_remove_last_from_array(VALUE self, VALUE ary){
  VALUE rAry;
  ID id_pop;
  //static unsigned long id_pop;
  rAry = ary;
  id_pop = rb_intern("pop");
  rb_funcall(rAry, id_pop, 0);

  return rAry;
}

static VALUE t_my_class_method(VALUE self){

  return Qnil;
}

static VALUE t_create(VALUE self, VALUE payload){
  VALUE instance;

  instance = rb_funcall(self, rb_intern("new"), 0);
  rb_iv_set(instance, "@voltage", payload);
  return instance;
}

void Init_sub_with_block(VALUE parent){
  subWithBlock = rb_define_class("SubWithBlock", parent);
  rb_define_method(subWithBlock, "my_method",t_my_method,0);
  rb_define_method(subWithBlock, "remove_last_from_array",
                  t_remove_last_from_array,1);
  rb_define_singleton_method(subWithBlock,
                            "my_class_method",
                            t_my_class_method,
                            0);
  rb_define_singleton_method(subWithBlock, "create", t_create, 1);
}
