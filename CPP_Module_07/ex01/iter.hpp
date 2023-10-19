template<typename T, typename F>
void iter(T* array, int length, F function)
{
    for (size_t i = 0; i < (size_t)length; i++)
        function(array[i]);
}