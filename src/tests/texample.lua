
local a = student:create(1)
print(a:get_name(), a:get_id())

local b = student:create(2)
print(b:get_name(), b:get_id())

-- error
-- print(b:unqiue())
local c = tolua.cast(b, 'stuff')
print(c:unique())
