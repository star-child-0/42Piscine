#ifdef FT_ABS_H
# define FT_ABS_H
# define ABS(Value) (Value < 0 ? Value = -Value : Value = Value)
#endif
