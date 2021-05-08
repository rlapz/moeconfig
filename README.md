# moeconfig
A simple config parser

`Example config file`
----

```
!SECTION_1      # section 1
var1    = test1 # var1
var2    = yes
var3    =       # empty value (return NULL by default)
var4             # ignored
var5    = hello world   #


!SECTION_2      # section 2
var1    = test2
var2    = no

!SECTION_2      # duplicate section (ignored)
var1    = 
```
