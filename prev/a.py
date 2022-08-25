a = {"a": 2}
b = {"b": 3}
c = dict()

a.setdefault("a", 3)  # a = {"a": 2}
b.setdefault("z", 4)  # b = {"b": 3, "z": 4}

a["x"] = 5

a.keys()  # dict_keys(["a"])
a.update({1: 2})
print(a)

a.pop("a")
print(a)

a.popitem()
print(a)
a.popitem()
print(a)
