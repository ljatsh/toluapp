for i=1,10 do
 assert(a[i]==i)
end

for i=2,10 do
 assert(p[i-1].y==p[i].x)
end
 
for i=1,10 do
 assert(M.a[i]==i)
end

for i=2,10 do
 assert(M.p[i-1].y==M.p[i].x)
end

for i=1,10 do
 assert(pp[i].x==M.p[i].x and p[i].y == M.pp[i].y)
end

for i=1,10 do
 assert(array.a[i] == parray.a[i])
 assert(array.p[i].x == parray.pp[i].x and array.p[i].y == parray.pp[i].y)
end

for i=1,10 do
 array.a[i] = a[10-i+1]
	M.a[i] = 10-i+1
	assert(array.a[i]==M.a[i])
end

for i=2,10 do
 array.p[i] = array.pp[1]
	assert(array.p[i].x==0 and array.p[i].y==1)
end

print("Array test OK")
dump_lua(1, true, false, 2.0, 'hello', {10, 11, name='lj@sh', t=function() end, p = print})

dump_lua({n=1, info={a='lj', b={age=10, c={p=1}}}})

local t2
local t = {name = 'lj@sh'}
t2 = {1, 2, t}
t.r = t2
dump_lua(t2)
dump_lua(_G)
