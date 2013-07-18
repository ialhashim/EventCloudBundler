// This file is automatically generated; do not edit.\n
/**

jsontool

*/

#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <cstdarg>
#include <memory>

namespace jsontool {

using namespace std;

class var;

class Null {
};

static const Null null;

static const Null undefined;

typedef bool boolean;
typedef long double number;
typedef const char* cstring;
typedef string string;

typedef map<string, var> Object;
typedef vector<var> Array;
typedef Object O_;
typedef Array A_;

static inline var parse(string str);
static inline string stringify(var value);

enum ValueType {
TYPE_UNDEFINED,
TYPE_NULL,
TYPE_BOOLEAN,
TYPE_NUMBER,
TYPE_STRING,
TYPE_OBJECT,
TYPE_ARRAY
};

class TypeAdapter {

public:

  var* value;

  ValueType type;

  virtual boolean toBoolean(var &);

  virtual number toNumber(var &);

  virtual string toString(var &);

  virtual string toJSON(var &);

  virtual var &subscript(var &, var);

  virtual var &getParent(var &);

  virtual string &getTempKey(var &);

  virtual var &setTemp(var &, string);

  virtual void promoteTemp(var &);

  boolean &getBoolean(var &value);

  number &getNumber(var &value);

  string &getString(var &value);

  Object &getObject(var &value);

  Array &getArray(var &value);

};

class UndefinedAdapter: public TypeAdapter {

public:

  UndefinedAdapter() :
    TypeAdapter() {
    type = TYPE_UNDEFINED;
  }

};

class NullAdapter: public TypeAdapter {

public:

  NullAdapter() :
    TypeAdapter() {
    type = TYPE_NULL;
  }

};

class BooleanAdapter: public TypeAdapter {

public:

  number toNumber(var &);
  string toString(var &);
  BooleanAdapter() :
    TypeAdapter() {
    type = TYPE_BOOLEAN;
  }

};

class NumberAdapter: public TypeAdapter {

public:

  boolean toBoolean(var &);
  string toString(var &);

  NumberAdapter() :
    TypeAdapter() {
    type = TYPE_NUMBER;
  }

};

class StringAdapter: public TypeAdapter {

public:

  boolean toBoolean(var &);
  number toNumber(var &);
  string toJSON(var &);

  StringAdapter() :
    TypeAdapter() {
    type = TYPE_STRING;
  }

};

class ObjectAdapter: public TypeAdapter {

public:

  boolean toBoolean(var &);
  number toNumber(var &);
  string toString(var &);
  var &subscript(var &, var);
  virtual void promoteTemp(var &value);

  ObjectAdapter() :
    TypeAdapter() {
    type = TYPE_OBJECT;
  }

};

class ArrayAdapter: public TypeAdapter {

public:

  boolean toBoolean(var &);
  number toNumber(var &);
  string toString(var &);
  var &subscript(var &, var);
  virtual void promoteTemp(var &value);

  ArrayAdapter() :
    TypeAdapter() {
    type = TYPE_ARRAY;
  }

};
class compare {

public:

  static var toPrimitive(var& x);

  static bool equality(var& x, var& y);

  static bool relation(var& x, var& y);

};
class var {

protected:

  var* parent;

  string tempKey; // string or unsigned

  Object tempKeys;

  bool isTemp;

  TypeAdapter* getAdapter(ValueType type) {

    static map<ValueType, TypeAdapter*> adapters;

    if (adapters.empty()) {

      static UndefinedAdapter a;
      static NullAdapter b;
      static BooleanAdapter c;
      static NumberAdapter d;
      static StringAdapter e;
      static ObjectAdapter f;
      static ArrayAdapter g;

      adapters[TYPE_UNDEFINED] = &a;
      adapters[TYPE_NULL] = &b;
      adapters[TYPE_BOOLEAN] = &c;
      adapters[TYPE_NUMBER] = &d;
      adapters[TYPE_STRING] = &e;
      adapters[TYPE_OBJECT] = &f;
      adapters[TYPE_ARRAY] = &g;

    }

    return adapters[type];

  }

  // initializers

  void reset() {

    booleanValue = false;
    numberValue = 0;
    stringValue = "null";

  }

  void init() {

    isTemp = false;
    isTemp= false;
    adapter = getAdapter(TYPE_UNDEFINED);

  }

  void setFromVariant(const var &value) {

    reset();
    adapter = getAdapter(TYPE_UNDEFINED);
    copy(value);

  }

  void setFromUndefined() {

    reset();
    adapter = getAdapter(TYPE_UNDEFINED);

  }

  void setFromNull() {

    reset();
    stringValue = "null";
    adapter = getAdapter(TYPE_NULL);

  }

  void setFromBoolean(boolean value) {

    reset();
    booleanValue = value;
    adapter = getAdapter(TYPE_BOOLEAN);

  }

  void setFromNumber(number value) {

    reset();
    numberValue = value;
    adapter = getAdapter(TYPE_NUMBER);

  }

  void setFromString(string value) {

    reset();
    stringValue = value;
    adapter = getAdapter(TYPE_STRING);

  }

  void setFromObject(Object value) {

    reset();
    objectValue = shared_ptr<Object> (new Object(value));
    adapter = getAdapter(TYPE_OBJECT);

  }

  void setFromArray(Array value) {

    reset();
    Array v = value;
    arrayValue = shared_ptr<Array> (new Array(value));
    adapter = getAdapter(TYPE_ARRAY);

  }

  template<typename T>
  static pair<T, T> arrayToPair(T(&p)[2]) {

    return make_pair(p[0], p[1]);
  }

  TypeAdapter* adapter;

  boolean booleanValue;

  number numberValue;

  string stringValue;

  shared_ptr<Object> objectValue;

  shared_ptr<Array> arrayValue;

public:

  friend class compare;
  friend class Parser;
  friend class TypeAdapter;

  // cast operators

  operator boolean() {
    return adapter->toBoolean(*this);
  }

  operator unsigned() {
    return adapter->toNumber(*this);
  }

  operator number() {
    return adapter->toNumber(*this);
  }

  operator string() {
    return adapter->toString(*this);
  }

  operator Object() const {
    return *objectValue;
  }

  operator Array() const {
    return *arrayValue;
  }

  void checkTempMember() {

    if (isTemp) {

      isTemp = false;

      parent->adapter->promoteTemp(*this);

    }

  }

  void copy(var source) {

    adapter = source.adapter;

    booleanValue = source.booleanValue;

    numberValue = source.numberValue;

    stringValue = source.stringValue;

    objectValue = source.objectValue;

    arrayValue = source.arrayValue;

  }

  // equality operators

  template<typename T>
  bool operator ==(T val) {

    var rhs = val;
    return compare::equality(*this, rhs);

  }

  template<typename T>
  bool operator !=(T val) {

    var rhs = val;
    return !compare::equality(*this, rhs);

  }

  // http://es5.github.com/#x11.8.1

  template<typename T>
  bool operator <(T val) {

    var rhs = val;
    return compare::relation(*this, rhs);

  }

  // http://es5.github.com/#x11.8.2

  template<typename T>
  bool operator >(T val) {

    var rhs = val;
    return compare::relation(rhs, *this);

  }

  // http://es5.github.com/#x11.8.3

  template<typename T>
  bool operator <=(T val) {

    var rhs = val;
    return !compare::relation(rhs, *this);

  }

  // http://es5.github.com/#x11.8.4

  template<typename T>
  bool operator >=(T val) {

    var rhs = val;
    return !compare::relation(*this, rhs);

  }

  // assignment operators

  var operator =(var rhs) {

    copy(rhs);

    checkTempMember();

    return *this;
  }

  var operator +=(var rhs) {
    numberValue += rhs.numberValue;
    stringValue += rhs.stringValue;
    return *this;
  }

  var operator -=(var rhs) {
    numberValue -= rhs.numberValue;
    return *this;
  }

  var operator *=(var rhs) {
    numberValue *= rhs.numberValue;
    return *this;
  }

  var operator /=(var rhs) {
    numberValue /= rhs.numberValue;
    return *this;
  }

  // subscript notation

  template<typename T>
  var &operator [](const T &key) {

    return adapter->subscript(*this, key);

  }

  // ctors

  var() {

    init();
    setFromUndefined();

  }

  var(Null) {

    init();
    setFromNull();

  }

  var(bool value) {

    init();
    setFromBoolean(value);

  }

  var(long double value) {

    init();
    setFromNumber(value);

  }

  var(double value) {

    init();
    setFromNumber(value);

  }

  var(long value) {

    init();
    setFromNumber(value);

  }

  var(int value) {

    init();
    setFromNumber(value);

  }

  var(unsigned value) {

    init();
    setFromNumber(value);

  }

  var(unsigned long value) {

    init();
    setFromNumber(value);

  }

  var(cstring value) {

    init();
    setFromString(value);

  }

  var(string value) {

    init();
    setFromString(value);

  }

  var(Object value) {

    init();
    setFromObject(value);

  }

  var(Array value) {

    init();
    setFromArray(value);

  }

  // vector

  template<typename T>
  var(vector<T> value) {

    init();
    setFromArray(Array(value.begin(), value.end()));

  }

  // map

  template<typename T1, typename T2>
  var(map<T1, T2> value) {

    init();
    setFromObject(Object(value.begin(), value.end()));

  }

  // c array

  template<typename T, int N>
  var(T(& value)[N]) {

    init();
    setFromArray(Array(value, value + sizeof(value) / sizeof(T)));

  }

  // two dimensional c array

  template<typename T, int N>
  var(T(& value)[N][2]) {

    init();
    map<string, var> result;
    transform(value, value + N, inserter(result, result.begin()),
        arrayToPair<T> );
    setFromObject(result);

  }

  // type checks

  inline bool isUndefined() {

    return adapter->type == TYPE_UNDEFINED;

  }
  inline bool isNull() {

    return adapter->type == TYPE_NULL;

  }
  inline bool isBoolean() {

    return adapter->type == TYPE_BOOLEAN;

  }
  inline bool isNumber() {

    return adapter->type == TYPE_NUMBER;

  }
  inline bool isString() {

    return adapter->type == TYPE_STRING;

  }
  inline bool isObject() {

    return adapter->type == TYPE_OBJECT;

  }
  inline bool isArray() {

    return adapter->type == TYPE_ARRAY;

  }

  string toJSON() {
    return adapter->toJSON(*this);
  }

};
class ParseError: public exception {

protected:

  string message;

  void setup(const int aLine, const int aPosition, const string& aMessage) {

    stringstream ss;
    ss << "Parse error at line " << aLine << ", position " << aPosition << ": " << aMessage;
    message = ss.str();

  }

public:

  explicit ParseError(const int aLine, const int aPosition, const string& aMessage) {
    setup(aLine, aPosition, aMessage);
  }

  explicit ParseError(const string& aMessage) {
    setup(0, 0, aMessage);
  }

  virtual ~ParseError() throw () {
  }

  const char * what() const throw () {
    return message.c_str();
  }

};
class Parser {

public:

  /**
   * Try to repair broken JSON
   */
  bool repair;

  /**
   * Report all errors
   */
  bool report;



  Parser(bool aRepair, bool aReport) {
    repair = aRepair;
    report = aReport;
    hasError = false;
  }

  Parser()  {
    repair = false;
    report = false;
    hasError = false;
  }

protected:

  bool hasError;

  void warn(ParseError error, bool repaired) {

    if (repaired) {

      cerr << error.what() << " (repaired)" << endl;
      return;

    }
    if (report) {

      hasError = true;
      cerr << error.what() << endl;
      return;

    }

    throw error;

  }
  void warn(ParseError error) {

    warn(error, false);

  }

public:

  enum ParserState {
    STATE_WHITESPACE, STATE_NUMBER, STATE_STRING
  };


  void append(var &context, string key, var value);

  var parse(string str);

};

/**
 * Type adapter
 */

// final

boolean &TypeAdapter::getBoolean(var &value) {
  return value.booleanValue;
}

number &TypeAdapter::getNumber(var &value) {
  return value.numberValue;
}

string &TypeAdapter::getString(var &value) {
  return value.stringValue;
}

Object &TypeAdapter::getObject(var &value) {
  return *value.objectValue;
}

Array &TypeAdapter::getArray(var &value) {
  return *value.arrayValue;
}

var &TypeAdapter::setTemp(var &value, string key) {

  value.tempKeys[key] = var();
  value.tempKeys[key].isTemp = true;
  value.tempKeys[key].parent = (&value);
  value.tempKeys[key].tempKey = key;
  return value.tempKeys[key];

}

void TypeAdapter::promoteTemp(var &value) {

}

// virtual

boolean TypeAdapter::toBoolean(var &value) {
  return value.booleanValue;
}

number TypeAdapter::toNumber(var &value) {
  return value.numberValue;
}

string TypeAdapter::toString(var &value) {
  return value.stringValue.c_str();
}

string TypeAdapter::toJSON(var &value) {
  return (string) value;
}

var &TypeAdapter::subscript(var &, var) {
  static var undefined;
  return undefined;
}

string &TypeAdapter::getTempKey(var &value) {

  return value.tempKey;

}

var &TypeAdapter::getParent(var &value) {

  return *value.parent;

}

// array adapter

number ArrayAdapter::toNumber(var &value) {
  return 0; // FIXME
}

boolean ArrayAdapter::toBoolean(var &) {
  return true;
}

string ArrayAdapter::toString(var &value) {

  Array &arrayValue = getArray(value);
  string &stringValue = getString(value);

  ostringstream ss;

  ss << "[";

  for (Array::iterator it = arrayValue.begin(); it != arrayValue.end(); ++it) {

    var& item = *it;

    if (it != arrayValue.begin())
      ss << ",";

    ss << stringify(item);

  }

  ss << "]";

  stringValue = ss.str();

  return stringValue;

}

var& ArrayAdapter::subscript(var &value, var key) {

  Array &arrayValue = getArray(value);

  return key < arrayValue.size() ? arrayValue[key] : setTemp(value, key);

}

void ArrayAdapter::promoteTemp(var &value) {

  unsigned index = (var)getTempKey(value);
  Array &a = getArray(getParent(value));

  a.resize(index + 1);
  a[index] = value;
  // TODO: remove temporary value
  // parent->tempKeys.erase((string)(var)tempArrayKey);

}

// boolean adapter

number BooleanAdapter::toNumber(var &value) {
  return getBoolean(value) == false ? 0 : 1;
}
string BooleanAdapter::toString(var &value) {
  return getBoolean(value) == false ? "false" : "true";
}

// number adapter

boolean NumberAdapter::toBoolean(var &value) {
  return getNumber(value) == 0 ? false : true;
}

string NumberAdapter::toString(var &value) {
  string &stringValue = getString(value);
  ostringstream ss;
  stringValue = ss << getNumber(value) ? ss.str() : "NaN";
  return stringValue;
}

// object adapter

number ObjectAdapter::toNumber(var &) {
  return 0;
}

boolean ObjectAdapter::toBoolean(var &) {
  return true;
}

string ObjectAdapter::toString(var &value) {

  Object &objectValue = getObject(value);
  string &stringValue = getString(value);

  ostringstream ss;

  ss << "{";

  for (Object::iterator it = objectValue.begin(); it
      != objectValue.end(); ++it) {

    var& item = it->second;

    if (it != objectValue.begin())
      ss << ",";

    ss << "\"" << it->first << "\":";

    ss << stringify(item);

  }

  ss << "}";

  stringValue = ss.str();

  return stringValue;

}

var& ObjectAdapter::subscript(var &value, var key) {

  Object &objectValue = getObject(value);

  return objectValue.count(key) ? objectValue[key] : setTemp(value, key);

}

void ObjectAdapter::promoteTemp(var &value) {

  getObject(getParent(value))[getTempKey(value)] = value;
  // TODO: remove temporary value
  // parent->tempKeys.erase(tempObjectKey);

}

// string adapter

boolean StringAdapter::toBoolean(var &value) {
  return getString(value) == "" ? false : true;
}

number StringAdapter::toNumber(var &value) {
  number n;
  istringstream ss(getString(value));
  return ss >> n ? n : 0;
}

string StringAdapter::toJSON(var &value) {

  string &str = getString(value);

  string::iterator it;

  char character;

  stringstream ss;

  ss << '"';

  for (it = str.begin(); it < str.end(); it++) {

    character = *it;

    switch (character) {

    case '"':
      ss << "\\\"";
      continue;
    case '\\':
      ss << "\\\\";
      continue;
    case '\b':
      ss << "\\b";
      continue;
    case '\f':
      ss << "\\f";
      continue;
    case '\n':
      ss << "\\n";
      continue;
    case '\r':
      ss << "\\r";
      continue;
    case '\t':
      ss << "\\t";
      continue;
    default:
      // TODO: check bad characters, encode unicode?
      ss << character;

    }

  }

  ss << '"';

  return ss.str();

}

var compare::toPrimitive(var& x) {
  if (!(x.isArray() || x.isObject()))
    return x;
  return (string) x;
}

// ES5 11.9.3 The Abstract Equality Comparison Algorithm
// http://es5.github.com/#x11.9.3

// The comparison x == y, where x and y are values, produces true or false. 
// Such a comparison is performed as follows:

bool compare::equality(var& x, var& y) {

  // 1. If Type(x) is the same as Type(y), then
  if (x.adapter->type == y.adapter->type) {

    // 1. If Type(x) is Undefined, return true.
    if (x.isUndefined())
      return true;

    // 2. If Type(x) is Null, return true.
    if (x.isNull())
      return true;

    // 3. If Type(x) is Number, then
    if (x.isNumber()) {

      // 1. If x is NaN, return false.
      // 2. If y is NaN, return false.

      // (TODO: NaN checks?)

      // 3. If x is the same Number value as y, return true.
      if (x.numberValue == y.numberValue)
        return true;

      // 4. If x is +0 and y is -0, return true.
      if (x.numberValue == +0 && y.numberValue == -0)
        return true;

      // 5. If x is -0 and y is +0, return true.
      if (x.numberValue == -0 && y.numberValue == +0)
        return true;

      // 6. Return false.
      return false;

    }

    // 4. If Type(x) is String, then return true if x and y are exactly the same sequence of characters 
    //    (same length and same characters in corresponding positions). Otherwise, return false.
    if (x.isString())
      return x.stringValue == y.stringValue;

    // 5. If Type(x) is Boolean, return true if x and y are both true or both false. Otherwise, return false.
    if (x.isBoolean())
      return x.booleanValue == y.booleanValue;

    // 6. Return true if x and y refer to the same object. Otherwise, return false.
    if (x.isObject())
      return x.objectValue == y.objectValue;
    if (x.isArray())
      return x.arrayValue == y.arrayValue;

    return false;

  }
  // 2. If x is null and y is undefined, return true.
  if (x.isNull() && y.isUndefined())
    return true;

  // 3. If x is undefined and y is null, return true.
  if (x.isUndefined() && y.isNull())
    return true;

  // 4. If Type(x) is Number and Type(y) is String, 
  //    return the result of the comparison x == ToNumber(y).
  if (x.isNumber() && y.isString())
    return x == (number) y;

  // 5. If Type(x) is String and Type(y) is Number, 
  //    return the result of the comparison ToNumber(x) == y.
  if (x.isString() && y.isNumber())
    return (var) (number) x == y;

  // 6. If Type(x) is Boolean, 
  //    return the result of the comparison ToNumber(x) == y.
  if (x.isBoolean())
    return (var) (number) x == y;

  // 7. If Type(y) is Boolean, 
  //    return the result of the comparison x == ToNumber(y).
  if (y.isBoolean())
    return x == (number) y;

  // 8. If Type(x) is either String or Number and Type(y) is Object, 
  //    return the result of the comparison x == ToPrimitive(y).
  if ((x.isString() || x.isNumber()) && (y.isObject() || y.isArray()))
    return x == (string) y;

  // 9. If Type(x) is Object and Type(y) is either String or Number, 
  //    return the result of the comparison ToPrimitive(x) == y.
  if ((x.isObject() || x.isArray()) && (y.isString() || y.isNumber()))
    return (var) (string) x == y;

  // 10. Return false.
  return false;

}

// ES5 11.8.5 The Abstract Relational Comparison Algorithm
// http://es5.github.com/#x11.8.5

/*
 The comparison x < y, where x and y are values, produces true, false, or undefined (which indicates that at least one operand is NaN). In addition to x and y the algorithm takes a Boolean flag named LeftFirst as a parameter. The flag is used to control the order in which operations with potentially visible side-effects are performed upon x and y. It is necessary because ECMAScript specifies left to right evaluation of expressions. The default value of LeftFirst is true and indicates that the x parameter corresponds to an expression that occurs to the left of the y parameter’s corresponding expression. If LeftFirst is false, the reverse is the case and operations must be performed upon y before x.
 */

bool compare::relation(var& x, var& y) {

  // 1. If the LeftFirst flag is true, then
  // 1. Let px be the result of calling ToPrimitive(x, hint Number).
  // 2. Let py be the result of calling ToPrimitive(y, hint Number).
  // 2. Else the order of evaluation needs to be reversed to preserve left to right evaluation
  // 1. Let py be the result of calling ToPrimitive(y, hint Number).
  // 2. Let px be the result of calling ToPrimitive(x, hint Number).

  // NOTE: The order of evaluation shouldn't matter in this case; don't use LeftFirst.

  var px = toPrimitive(x);
  var py = toPrimitive(y);

  // 3. If it is not the case that both Type(px) is String and Type(py) is String, then
  if (!(px.isString() && py.isString())) {

    // 1. Let nx be the result of calling ToNumber(px). 
    //    Because px and py are primitive values evaluation order is not important.
    number nx = px;

    // 2. Let ny be the result of calling ToNumber(py).
    number ny = py;

    // 3. If nx is NaN, return undefined.
    // 4. If ny is NaN, return undefined.

    // TODO: NaN checks?

    // 5. If nx and ny are the same Number value, return false.
    if (nx == ny)
      return false;

    // 6. If nx is +0 and ny is −0, return false.
    if (nx == +0 && ny == -0)
      return false;

    // 7. If nx is −0 and ny is +0, return false.
    if (nx == -0 && ny == +0)
      return false;

    // 8. If nx is +∞, return false.
    // 9. If ny is +∞, return true.
    // 10. If ny is −∞, return false.
    // 11. If nx is −∞, return true.

    // TODO: infinity checks?

    // 12. If the mathematical value of nx is less than the mathematical value of ny 
    //     —note that these mathematical values are both finite and not both zero—return true. Otherwise, return false.

    return nx < ny;

  } else {
    // 4. Else, both px and py are Strings
    // 1. If py is a prefix of px, return false. (A String value p is a prefix of String value q ifq can be the result of concatenating p and some other String r. Note that any String is a prefix of itself, because r may be the empty String.)
    // 2. If px is a prefix of py, return true.
    // 3. Let k be the smallest nonnegative integer such that the character at position kwithin px is different from the character at position k within py. (There must be such a k, for neither String is a prefix of the other.)
    // 4. Let m be the integer that is the code unit value for the character at position kwithin px.
    // 5. Let n be the integer that is the code unit value for the character at position kwithin py.
    // 6. If m < n, return true. Otherwise, return false.

    // NOTE: Should be close enough to std::string behavior.

    return (string) px < (string) py;

  }
}

void Parser::append(var &context, string key, var value) {

  if (context.isObject()) {
    context[key] = value;

  } else if (context.isArray()) {

    context.arrayValue->push_back(value);

  }

}

var Parser::parse(string str) {

  string::iterator it;
  char character;
  ParserState state = STATE_WHITESPACE;
  stringstream keyBuffer("");
  stringstream valBuffer("");
  int index = -1;
  int linePosition = -1;
  int line = 1;

  bool hasEscape = false;
  bool isKey = false;
  bool expectColon = false;

  var context = Array();
  Array contextStack;
  contextStack.push_back(context);

  for (it = str.begin(); it < str.end(); it++) {

    ++index;
    ++linePosition;

    character = *it;

    switch (state) {

    case STATE_WHITESPACE:

      // whitespace

      if (character == '\n') {

        ++line;
        linePosition = -1;

        continue;

      }

      if (isspace(character)) {

        continue;

      }

      // comma

      if (character == ',') {

        if (context.isObject()) {
          isKey = true;
        }
        continue;

      }

      // null

      if (character == 'n' && str.compare(index, 4, "null") == 0) {

        append(context, keyBuffer.str(), null);

        it += 3;
        index += 3;
        linePosition += 3;

        continue;

      }

      // boolean

      if (character == 't' && str.compare(index, 4, "true") == 0) {

        append(context, keyBuffer.str(), null);

        it += 3;
        index += 3;
        linePosition += 3;

        continue;

      }

      if (character == 'f' && str.compare(index, 5, "false") == 0) {

        append(context, keyBuffer.str(), null);

        it += 4;
        index += 4;
        linePosition += 4;

        continue;

      }

      // number

      if (isdigit(character) || character == '-') {

        state = STATE_NUMBER;
        valBuffer << character;
        continue;

      }

      // string

      if (character == '"') {

        state = STATE_STRING;
        continue;

      }

      // object

      if (character == '{') {

        var newContext = Object();

        append(context, keyBuffer.str(), newContext);
        keyBuffer.str("");

        context = newContext;
        contextStack.push_back(context);

        isKey = true;
        continue;

      }

      if (character == '}') {

        contextStack.pop_back();
        context = contextStack.back();
        continue;

      }

      // array

      if (character == '[') {

        var newContext = Array();

        append(context, keyBuffer.str(), newContext);
        keyBuffer.str("");

        context = newContext;
        contextStack.push_back(context);

        isKey = false;
        continue;

      }

      if (character == ']') {

        contextStack.pop_back();
        context = contextStack.back();

        continue;

      }

      if (character == ':') {

        if (expectColon) {

          expectColon = false;

          continue;

        }

        warn(ParseError(line, linePosition, "Found unexpected colon"), repair);

        continue;

      }

      keyBuffer.str("");
      warn(ParseError(line, linePosition,
          "Found unexpected character: " + str.substr(index, 1)), repair);

      continue;

    case STATE_NUMBER:

      if (character == ']' || character == '}' || character == ',') {

        if (character == ']' || character == '}')
          it--;

        state = STATE_WHITESPACE;
        append(context, keyBuffer.str(), strtod(valBuffer.str().c_str(), 0));
        keyBuffer.str("");
        valBuffer.str("");

        if (character == ',') {

          if (context.isObject()) {

            isKey = true;

          }

        }

        continue;

      }

      //TODO: don't allow more than one decimal dot
      //TODO: scientific notation
      if (isdigit(character) || character == '-' || character == '.') {

        valBuffer << character;
        continue;

      } else {

        warn(ParseError(line, linePosition,
            "Expected number, found " + str.substr(index, 1)), repair);

      }

    case STATE_STRING: {

      stringstream &buffer = isKey ? keyBuffer : valBuffer;

      if (hasEscape) {

        hasEscape = false;

        switch (character) {

        case '"':
        case '\\':
        case '/':
          buffer << character;
          continue;

        case 'b':
          buffer << '\b';
          continue;
        case 'f':
          buffer << '\f';
          continue;
        case 'n':
          buffer << '\n';
          continue;
        case 'r':
          buffer << '\r';
          continue;
        case 't':
          buffer << '\t';
          continue;

          // TODO: \u unicode escapes

        }

        stringstream ss;
        ss << "Bad escape sequence: backslash " << character;
        ParseError err = ParseError(line, linePosition, ss.str());

        if (repair) {

          buffer << "\\" << character;

        }

        warn(err, repair);

        // buffer << character;
        // continue;

      }

      if (character == '\\') {

        hasEscape = true;
        continue;

      }

      //TODO: disallow some characters, or only allow certain character


      if (character == '"') {

        state = STATE_WHITESPACE;

        if (!isKey) {

          append(context, keyBuffer.str(), valBuffer.str());
          keyBuffer.str("");
          valBuffer.str("");
          // isKey = true;
          continue;

        }
        // it was a key
        // TODO: throw if no colon
        expectColon = true;
        isKey = false;
        continue;

      }

      buffer << character;
      continue;

    }
    }

  }

  if (state == STATE_NUMBER) {
    append(context, keyBuffer.str(), strtod(valBuffer.str().c_str(), 0));
  }

  if (hasError) {

    hasError = false;
    throw(ParseError("Multiple errors."));

  }

  return context[0];

}

static Parser parser;

static inline var parse(string json) {

return parser.parse(json);

}

static inline string stringify(var value) {

return value.toJSON();

}

ostream& operator<<(ostream &os, var value) {

return os << (string)value;

}

}