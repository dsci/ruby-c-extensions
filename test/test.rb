require 'rubygems'
#gem 'minitest'
require 'minitest/autorun'
require 'minitest/spec'

require './lib/ary'

describe MyTest do
  before do
    @test = MyTest.new
  end

  it "has methods" do
    @test.must_respond_to(:remove)
    @test.must_respond_to(:add)
    @test.must_respond_to(:own_method)
    @test.must_respond_to(:length_of_arr)
  end

  it "has Object as superclass" do
    MyTest.superclass.must_equal Object
  end

  it "class is MyTest" do
    @test.class.must_equal MyTest
  end

  it "adds something" do
    @test.add(1)

    @test.instance_variable_get(:@arr).size.must_equal 1
    [1].must_equal @test.instance_variable_get(:@arr)

  end

  it "removes something" do
    @test.add(2)
    @test.remove(2)
    @test.instance_variable_get(:@arr).must_be_empty
  end

  it "#own_method returns a String" do
    @test.own_method.must_be_instance_of String
    @test.own_method.must_equal "String"
  end

  it "#length_of_arr returns the array size" do
    @test.add(2)
    @test.length_of_arr.must_equal 1
  end
end

describe MyChildTest do

  before do
    @child = MyChildTest.new
    p @child.foo
  end

  it "should be a subclass of MyTest" do
    MyChildTest.superclass.must_equal MyTest
  end
end

describe SubWithBlock do

  before do
    @with_block = SubWithBlock.new
  end

  describe "class methods" do

    it "provides #my_class_method" do
      SubWithBlock.must_respond_to(:my_class_method)
    end

    it "provides #create" do
      SubWithBlock.must_respond_to(:create)
    end

    describe "#create" do

      it "returns an instance of SubWithBlock" do
        @sub = SubWithBlock.create(12)
        @sub.instance_variable_get(:@voltage).must_equal 12
        @sub.must_be_instance_of SubWithBlock
      end

    end

  end

  it "has methods" do
    @with_block.must_respond_to(:my_method)
    @with_block.must_respond_to(:remove_last_from_array)
  end

  it "should be a subclass of MyTest" do
    SubWithBlock.superclass.must_equal MyChildTest
  end

  it "should yield the block" do
    k = @with_block.my_method do
      return "hello"
    end

    k.must_equal "hello"
  end

  it "#remove_last_from_array" do
    ary = [1]
    ary = @with_block.remove_last_from_array(ary)
    ary.must_be_empty
  end

end
