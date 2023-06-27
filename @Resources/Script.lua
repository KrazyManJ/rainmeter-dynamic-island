function Map(value, fMin, fMax, tMin, tMax)
    return (value - fMin) * (tMax - tMin) / (fMax - fMin) + tMin;
end