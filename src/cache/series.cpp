//
// AUGMENTS
//
// Copyright 2021 Christopher Borsellino
// All rights reserved.
//

#include "series.h"
#include "error.h"

Series::Series(const nlohmann::json& json)
{
    try {
        id = json.at("id");
        name = json.at("name");
    }
    catch (...) {
        throw Error("Failed to parse series data.");
    }
}
