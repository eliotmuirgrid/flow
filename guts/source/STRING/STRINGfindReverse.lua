function STRINGfindReverse(Haystack, Needle)
    if Needle == "" then
       return Haystack:len() + 1 -- Empty needle matches at the end
    end
    local len_hay = Haystack:len()
    local len_needle = Needle:len()
    for i = len_hay - len_needle + 1, 1, -1 do
        if Haystack:sub(i, i + len_needle - 1) == Needle then
            return i
        end
    end
    return nil
end
