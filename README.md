# moeconfig

A simple config parser

`Example config file`
----

```
# test
# don't use inline comment

#default section
!DEFAULT
user		= admin # inline comment
test		= 	# blank value (default = NULL)
aaa 			# will be ignored
string		= hello world
var1		= yes

# other section
!OTHER	
user		= other
var1		= no

# duplicate section (ignored)
!OTHER	
user		= other_dup
var1		= yes 

# guest section
!GUEST
user		= guest
var1		= yes
```
