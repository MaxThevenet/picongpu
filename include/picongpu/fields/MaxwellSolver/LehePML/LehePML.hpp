/* Copyright 2013-2020 Axel Huebl, Heiko Burau, Rene Widera, Remi Lehe,
 *                     Sergei Bastrakov
 *
 * This file is part of PIConGPU.
 *
 * PIConGPU is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * PIConGPU is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with PIConGPU.
 * If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "picongpu/simulation_defines.hpp"
#include "picongpu/fields/MaxwellSolver/Lehe/Lehe.hpp"
#include "picongpu/fields/MaxwellSolver/LehePML/LehePML.def"

#include <cstdint>


namespace pmacc
{
namespace traits
{

    template<
        typename T_CurrentInterpolation,
        uint32_t T_cherenkovFreeDir
    >
    struct StringProperties<
        ::picongpu::fields::maxwellSolver::LehePML<
            T_CurrentInterpolation,
            T_cherenkovFreeDir
        >
    >
    {
        static StringProperty get()
        {
            auto propList =
                ::picongpu::fields::maxwellSolver::LehePML<
                    T_CurrentInterpolation,
                    T_cherenkovFreeDir
                >::getStringProperties();
            // overwrite the name of the YeePML solver (inherit all other properties)
            propList["name"].value = "LehePML";
            return propList;
        }
    };

} // namespace traits
} // namespace pmacc
