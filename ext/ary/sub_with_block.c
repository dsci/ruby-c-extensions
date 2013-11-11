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

void Init_sub_with_block(VALUE parent){
  subWithBlock = rb_define_class("SubWithBlock", parent);
  rb_define_method(subWithBlock, "my_method",t_my_method,0);
  rb_define_method(subWithBlock, "remove_last_from_array",
                  t_remove_last_from_array,1);
}