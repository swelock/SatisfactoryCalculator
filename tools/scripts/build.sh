#!/bin/bash

# Satisfactory Calculator Build Script (qmake)
# Usage: ./scripts/build.sh [debug|release] [clean]

set -e

# Configuration
PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
BUILD_TYPE="${1:-release}"
CLEAN="${2:-}"

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

echo -e "${BLUE}🏭 Satisfactory Calculator Build Script (qmake)${NC}"
echo -e "${BLUE}================================================${NC}"

# Check build type
case "$BUILD_TYPE" in
    debug|Debug|DEBUG)
        BUILD_TYPE="debug"
        echo -e "${YELLOW}📋 Build Type: Debug${NC}"
        ;;
    release|Release|RELEASE)
        BUILD_TYPE="release"
        echo -e "${YELLOW}📋 Build Type: Release${NC}"
        ;;
    *)
        echo -e "${RED}❌ Invalid build type: $BUILD_TYPE${NC}"
        echo -e "${YELLOW}💡 Usage: $0 [debug|release] [clean]${NC}"
        exit 1
        ;;
esac

cd "$PROJECT_ROOT"

# Clean build files if requested
if [ "$CLEAN" = "clean" ]; then
    echo -e "${YELLOW}🧹 Cleaning build files...${NC}"
    make clean 2>/dev/null || true
    rm -f Makefile Makefile.Debug Makefile.Release
    rm -f *.o moc_*.cpp ui_*.h
    rm -rf debug/ release/
fi

# Detect number of CPU cores for parallel build
if command -v nproc &> /dev/null; then
    CORES=$(nproc)
elif command -v sysctl &> /dev/null; then
    CORES=$(sysctl -n hw.ncpu)
else
    CORES=4
fi

echo -e "${BLUE}🔧 Configuring with qmake...${NC}"

# Check if qmake is available
if ! command -v qmake &> /dev/null; then
    echo -e "${RED}❌ qmake not found in PATH${NC}"
    echo -e "${YELLOW}💡 Please install Qt development tools${NC}"
    exit 1
fi

# Generate Makefile with qmake
if [ "$BUILD_TYPE" = "debug" ]; then
    qmake CONFIG+=debug satiscalculator.pro
else
    qmake CONFIG+=release satiscalculator.pro
fi

if [ $? -ne 0 ]; then
    echo -e "${RED}❌ qmake configuration failed${NC}"
    exit 1
fi

echo -e "${BLUE}🔨 Building with $CORES cores...${NC}"

# Build
make -j"$CORES"

if [ $? -ne 0 ]; then
    echo -e "${RED}❌ Build failed${NC}"
    exit 1
fi

echo -e "${GREEN}✅ Build completed successfully!${NC}"

# Check if executable was created
EXECUTABLE=""
if [ "$BUILD_TYPE" = "debug" ]; then
    if [ -f "debug/satiscalculator" ]; then
        EXECUTABLE="debug/satiscalculator"
    elif [ -f "satiscalculator" ]; then
        EXECUTABLE="satiscalculator"
    fi
else
    if [ -f "release/satiscalculator" ]; then
        EXECUTABLE="release/satiscalculator"
    elif [ -f "satiscalculator" ]; then
        EXECUTABLE="satiscalculator"
    fi
fi

if [ -n "$EXECUTABLE" ]; then
    echo -e "${GREEN}🎯 Executable created: $EXECUTABLE${NC}"
    
    # Show file size
    if command -v du &> /dev/null; then
        SIZE=$(du -h "$EXECUTABLE" 2>/dev/null || echo "Size unknown")
        echo -e "${BLUE}📏 Size: $SIZE${NC}"
    fi
    
    # Make executable
    chmod +x "$EXECUTABLE"
else
    echo -e "${YELLOW}⚠️  Executable not found in expected location${NC}"
fi

echo -e "${GREEN}🚀 Build process completed!${NC}"
echo -e "${BLUE}💡 To run the application:${NC}"
if [ -n "$EXECUTABLE" ]; then
    echo -e "   ./$EXECUTABLE"
else
    echo -e "   ./satiscalculator"
fi 