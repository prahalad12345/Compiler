define i32 @main() #0 {
	 %1 = alloca i32, align 4
	 %2 = alloca i32, align 4
	 %3 = alloca i32, align 4
	 store i32 6, ptr %1 , align 4
	 store i32 7, ptr %2 , align 4
	 store i32 9, ptr %3 , align 4
	 %4 = load i32, i32* %1, align 4
	 %5 = load i32, i32* %2, align 4
	 %6 = icmp sgt i32 %4 , %5

	 br i1 %6, label %7, label %14 

7:
	 %8 = load i32, i32* %1, align 4
	 %9 = load i32, i32* %2, align 4
	 %10 = add nsw i32 %8, %9
	 store i32 %10, ptr %1, align 4
	 %11 = load i32, i32* %3, align 4
	 %12 = load i32, i32* %2, align 4
	 %13 = add nsw i32 %11, %12
	 store i32 %13, ptr %1, align 4
	 br label %18

14:
	 %15 = load i32, i32* %1, align 4
	 %16 = load i32, i32* %2, align 4
	 %17 = sub nsw i32 %15, %16
	 store i32 %17, ptr %1, align 4
	 br label %18

18:
	 store i32 5, ptr %1 , align 4
	 ret i32 0
}