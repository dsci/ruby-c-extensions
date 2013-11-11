## Ruby C-API

Ruby is extendable with C. And I wanted to know how. 

It covers defining classes, subclassing and calling a block. 

## Usage

Install required gems first

```
bundle install
```

Compile the extension:

```
rake compile[:ary]
```

Run the test suite

```
rake test
```

## What else?

By the way, this is also possible with C++. The thing you have to do is, mark your Ruby extension entry function as ```extern```.

```cpp
/* a C++ header file. */
#include <ruby.h>

VALUE cTest;

/* a C++ source file. */
#include "hello.h"

extern "C" void Init_hello(){
  cTest = rb_define_class("MyTest", rb_cObject);
} 

```

In Ruby it is:

```ruby
class MyTest
end
```


**Author** : Daniel Schmidt (<dsci@code79.net>)

Feel free to modify. 