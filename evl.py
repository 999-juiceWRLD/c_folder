def create_variable_func(code):
    exec(code, globals())

create_variable_func('x = 10')
print(x) # prints 10
