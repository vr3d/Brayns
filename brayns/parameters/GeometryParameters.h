/* Copyright (c) 2015-2016, EPFL/Blue Brain Project
 * All rights reserved. Do not distribute without permission.
 * Responsible Author: Cyrille Favreau <cyrille.favreau@epfl.ch>
 *
 * This file is part of Brayns <https://github.com/BlueBrain/Brayns>
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License version 3.0 as published
 * by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more
 * details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef GEOMETRYPARAMETERS_H
#define GEOMETRYPARAMETERS_H

#include "AbstractParameters.h"

#include <brayns/common/types.h>

namespace brayns
{

/**
 * Defines how morphologies should be organized in space when the layout mode is
 * selected. The idea is to present the morphology in a grid with a given number
 * of columns, and a spacing in between. The spacing scale is the same as the
 * one from the morphologies.
 */
struct MorphologyLayout
{
    MorphologyLayout()
    : type( ML_NONE )
    , nbColumns( 0 )
    , verticalSpacing( 0 )
    , horizontalSpacing( 0 )
      {}

    MorphologyLayoutType type;
    size_t nbColumns;
    size_t verticalSpacing;
    size_t horizontalSpacing;
};

/** Manages geometry parameters
 */
class GeometryParameters : public AbstractParameters
{
public:
    /**
       Parse the command line parameters and populates according class members
     */
    GeometryParameters( );

    /** @copydoc AbstractParameters::print */
    void print( ) final;

    /** folder containing SWC and H5 files */
    std::string getMorphologyFolder( ) const { return _morphologyFolder; }

    /** PDB file */
    std::string getPDBFile( ) const { return _pdbFile; }

    /** folder containing mesh files */
    std::string getMeshFolder( ) const { return _meshFolder; }

    /** file containing circuit configuration */
    std::string getCircuitConfiguration( ) const { return _circuitConfig; }

    /** Binary representation of a scene to load */
    std::string getLoadCacheFile( ) const { return _loadCacheFile; }

    /** Binary representation of a scene to save */
    std::string getSaveCacheFile( ) const { return _saveCacheFile; }

    /** Circuit target */
    std::string getTarget( ) const { return _target; }

    /** Circuit compartment report */
    std::string getReport( ) const { return _report; }

    /** Radius multiplier applied to spheres, cones and cylinders.
     * @param value Radius multiplier. Multiplies the radius contained in the
     *        data source by the specified value.
     */
    void setRadiusMultiplier( const float value ) { _radiusMultiplier = value; }
    float getRadiusMultiplier( ) const { return _radiusMultiplier; }

    /** Radius correction applied to spheres and cylinders.
     * @param value Radius value. The radius contained in the data source is
     *        ignored and all geometries use the specified value.
     */
    void setRadiusCorrection( const float value ) { _radiusCorrection = value; }
    float getRadiusCorrection( ) const { return _radiusCorrection; }

    /** Enables a different color for every morphology/mesh when
    * loading them from a given folder
    */
    ColorScheme getColorScheme( ) const { return _colorScheme; }
    void setColorScheme( const ColorScheme value ) { _colorScheme = value; }

    /** Scene environment (0: none, 1: ground, 2: box ) */
    SceneEnvironment getSceneEnvironment( ) const { return _sceneEnvironment; }

    /** Morphology quality */
    GeometryQuality getGeometryQuality( ) const { return _geometryQuality; }

    /** Morphology section types*/
    size_t getMorphologySectionTypes( ) const
    {
        return _morphologySectionTypes;
    }

    /** Morphology layout */
    const MorphologyLayout& getMorphologyLayout() const
    {
        return _morphologyLayout;
    }

    /** Defines if cells with no simulation data should be loaded */
    size_t getNonSimulatedCells() const { return _nonSimulatedCells; }

    /** Defines the range of frames to be loaded for the simulation
        This is related to the current size of the texture that is limited to
        2 GB. This of course needs to be improved! */
    size_t getLastSimulationFrame() const { return _lastSimulationFrame; }
    size_t getFirstSimulationFrame() const { return _firstSimulationFrame; }

    /** Defines if multiple models should be generated to increase the
        rendering performance */
    bool getGenerateMultipleModels() const { return _generateMultipleModels; }

protected:

    bool _parse( const po::variables_map& vm ) final;

    std::string _morphologyFolder;
    std::string _pdbFile;
    std::string _h5Folder;
    std::string _meshFolder;
    std::string _circuitConfig;
    std::string _loadCacheFile;
    std::string _saveCacheFile;
    std::string _target;
    std::string _report;
    float  _radiusMultiplier;
    float  _radiusCorrection;
    ColorScheme _colorScheme;
    SceneEnvironment _sceneEnvironment;
    GeometryQuality _geometryQuality;
    size_t _morphologySectionTypes;
    MorphologyLayout _morphologyLayout;
    size_t _nonSimulatedCells;
    size_t _firstSimulationFrame;
    size_t _lastSimulationFrame;
    bool _generateMultipleModels;
};

}
#endif // GEOMETRYPARAMETERS_H
