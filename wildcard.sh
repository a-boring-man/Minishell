export FILE=`find source -name "*.c" | sed 's#.*/##g' | tr '\n' ' '`
sed -i "" "s#LST_SRC :=.*#LST_SRC := $FILE#g" Makefile
export FILE=`find include -name "*.h" | sed 's#.*/##g' | tr '\n' ' '`
sed -i "" "s#LST_INC :=.*#LST_INC := $FILE#g" Makefile
export FILE=`find source_bonus -name "*.c" | sed 's#.*/##g' | tr '\n' ' '`
sed -i "" "s#LST_SRC_BNS :=.*#LST_SRC_BNS := $FILE#g" Makefile
export FILE=`find include_bonus -name "*.h" | sed 's#.*/##g' | tr '\n' ' '`
sed -i "" "s#LST_INC_BNS :=.*#LST_INC_BNS := $FILE#g" Makefile